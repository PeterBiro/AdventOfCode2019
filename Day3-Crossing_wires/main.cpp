#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

void readInput(const char* fileName, std::vector <std::string> & firstLine, std::vector <std::string> & secondLine) {
	std::ifstream inputFile(fileName);

	std::string temp;
	std::getline(inputFile, temp);

	std::stringstream ss{ temp };

	std::string token;
	while (std::getline(ss, token, ','))
	{
		firstLine.push_back(token);
	}
	std::getline(inputFile, temp);
	std::stringstream ss2{ temp };
	
	while (std::getline(ss2, token, ','))
	{
		secondLine.push_back(token);
	}

}

int main() {
	std::vector <std::string> firstLine;
	std::vector <std::string> secondLine;
	readInput("input_1.txt", firstLine, secondLine);

	typedef std::pair <int, int> coord;
	coord position{0,0};
	int x_step{0};
	int y_step{0};

	std::map<coord, int> firstVisited;

	for (std::string element : firstLine) {
		switch (element.at(0)) {
		case 'U':
			x_step = 0;
			y_step = 1;
			break;
		case 'D':
			x_step = 0;
			y_step = -1;
			break;
		case 'R':
			x_step = 1;
			y_step = 0;
			break;
		case 'L':
			x_step = -1;
			y_step = 0;
			break;
		}
		int step = atoi(element.substr(1).c_str());
		for (int idx = 0; idx < step; ++idx) {
			position.first += x_step;
			position.second += y_step;
			firstVisited[position] = 1;
		}
	 }


	position = { 0, 0 };
	int closest{ -1 };

	for (std::string element : secondLine) {
		switch (element.at(0)) {
		case 'U':
			x_step = 0;
			y_step = 1;
			break;
		case 'D':
			x_step = 0;
			y_step = -1;
			break;
		case 'R':
			x_step = 1;
			y_step = 0;
			break;
		case 'L':
			x_step = -1;
			y_step = 0;
			break;
		}
		int step = atoi(element.substr(1).c_str());
		for (int idx = 0; idx < step; ++idx) {
			position.first += x_step;
			position.second += y_step;
			if (firstVisited.end() != firstVisited.find(position)) {
				if (abs(position.first) + abs(position.second) < closest || -1 == closest) {
					closest = abs(position.first) + abs(position.second);
				}
			}
		}
	}
	std::cout << "Szerintem: " << closest;
	
}