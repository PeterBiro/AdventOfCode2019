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

int main() {
	std::vector <int> modulesMass = readInput("input_1.txt");
	int fuelMass{ 0 };
	for(auto i : modulesMass){
		fuelMass += i / 3 - 2;
	}
	std::cout << fuelMass;
}