#include <vector>
#include <fstream>
#include <iostream>

std::vector <int> readInput(const char* fileName) {
	std::ifstream inputFile(fileName);
	int line;
	std::vector <int> inputVector;
	while (inputFile >> line) {
		inputVector.push_back(line);
	}
	return inputVector;
}

int calculateFuel(int i) {
	int fuelToAdd = i / 3 - 2;
	if (fuelToAdd < 1) {
		return 0;
	}
	else {
		return fuelToAdd + calculateFuel(fuelToAdd);
	}
}

int main() {
	std::vector <int> modulesMass = readInput("input_1.txt");
	int fuelMass{ 0 };
	for(auto i : modulesMass){
		fuelMass += calculateFuel(i);
	}
	std::cout << fuelMass;
}