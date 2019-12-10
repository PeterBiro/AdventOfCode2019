#include<iostream>
#include<string>
#include<vector>

bool hasDoubleDigit(int n) {
	std::string nString = std::to_string(n);
	std::vector <int> doubles{ 9,8,7,6,5,4,3 };

	for (auto d : doubles) {
		if (std::string::npos != nString.find(std::to_string(d*11)) && std::string::npos == nString.find(std::to_string(d * 111))) return true;
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
