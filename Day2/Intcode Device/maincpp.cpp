#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std::vector <int> readInput(const char* fileName) {
	
	std::ifstream inputFile(fileName);
	
	std::string temp;
	std::getline(inputFile, temp);

	std::stringstream ss{temp};

	std::vector  <int> inputVector;
	
	for (int i; ss >> i;) {
		inputVector.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}

	return inputVector;
}

void doProcess(std::vector <int> &intcode) {
	int op_index = 0;
	while (op_index < intcode.size()) {
		switch (intcode[op_index])
		{
		case 1:
			intcode[intcode[op_index + 3]] = intcode[intcode[op_index + 1]] + intcode[intcode[op_index + 2]];
			break;
		case 2:
			intcode[intcode[op_index + 3]] = intcode[intcode[op_index + 1]] * intcode[intcode[op_index + 2]];
			break;
		case 99:
			return;
		}
		op_index += 4;
	}
	std::cout << "no 99 was found\n";
	return;
}

int main() {
	std::vector <int> intcode;
	
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			intcode = readInput("input_1_m.txt");
			int fuelMass{ 0 };

			intcode[1] = i;
			intcode[2] = j;
			doProcess(intcode);

			std::cout << intcode[0] << std::endl;
			if (19690720 == intcode[0]) {
				std::cout << "HEUREKA!! " << intcode[1]<< intcode[2] << std::endl;
				break;
			}
		}
		if (19690720 == intcode[0]) break;
	}
}
