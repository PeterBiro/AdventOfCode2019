#include<iostream>
#include<string>
#include<vector>

bool hasDoubleDigit(int n) {
	std::string nString = std::to_string(n);
	std::vector <std::string> doubles{"99", "88", "77", "66", "55", "44", "33" };

	for (auto d : doubles) {
		if (std::string::npos != nString.find(d)) return true;
	}
	return false;
}

bool nonDecreasing(int n) {
	int r{ 10 };
	while ( 0 < n) {
		if (r < n % 10) {
			return false;
		}
		r = n % 10;
		n /= 10;
	}
	return true;
}


int main() {
	int lowerEnd{ 234208 };
	int upperEnd{ 765869 };
	int result{ 0 };

	for (int num = lowerEnd; num <= upperEnd; ++num) {
		if (hasDoubleDigit(num) && nonDecreasing(num)) ++result;
	}
	
	std::cout << "The answer is: " << result;
}
