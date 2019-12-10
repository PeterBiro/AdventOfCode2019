#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

std::vector<int> program;

void readInput(const char* fileName) {
	std::ifstream inputFile(fileName);

	std::string temp;
	std::getline(inputFile, temp);

	std::stringstream ss{ temp };

	std::string token;
	while (std::getline(ss, token, ','))
	{
		program.push_back(atoi(token.c_str()));
	}
}
void parseOpCode(int& p, int & o, int& f, int& s, int& t) {
	int code = program[p];
	o = code % 100;
	code /= 100;
	f = code % 10;
	code /= 10;
	s = code % 10;
	code /= 10;
	t = code % 10;
}

int getValue(int from, int mode) {
	if (0 == mode) return program[program[from]];
	return program[from];
}

void doProcess(int& p) {
	int opCode, firstMode, secondMode, thirdMode;
	parseOpCode(p, opCode, firstMode, secondMode, thirdMode);
	switch (opCode)
	{
	case 1:
		program[program[p + 3]] = getValue(p + 1, firstMode) + getValue(p + 2, secondMode);
		p += 4;
		break;
	case 2:
		program[program[p + 3]] = getValue(p + 1, firstMode) * getValue(p + 2, secondMode);
		p += 4;
		break;
	case 3:
		std::cout << "input:";
		int param;
		std::cin >> param;
		program[program[p + 1]] = param;
		p += 2;
		std::cout << std::endl;
		break;
	case 4:
		std::cout << getValue(p + 1, firstMode) <<std::endl;
		p += 2;
		break;
	case 99:
		std::cout <<"99 in switch - case. IMPOSSIBLE!"<< std::endl;
		break;
	default:
		std::cout << "Unknown opcode - something went wrong" << std::endl;
		break;
	}
}

int main() {
	readInput("input_1.txt");
	int position{ 0 };
	while (99 != program[position]) {
		doProcess(position);
	}
	std::cout << "valami";

}