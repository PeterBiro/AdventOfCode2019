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

void initStep(std::string code, int & x, int & y, int & s) {
	switch (code.at(0)) {
	case 'U':
		x = 0;
		y = 1;
		break;
	case 'D':
		x = 0;
		y = -1;
		break;
	case 'R':
		x = 1;
		y = 0;
		break;
	case 'L':
		x = -1;
		y = 0;
		break;
	}
	 s = atoi(code.substr(1).c_str());
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

	int totalStepCounter{ 0 };

	for (std::string element : firstLine) {
		int step;
		initStep(element, x_step, y_step, step);

		for (int idx = 0; idx < step; ++idx) {
			++totalStepCounter;
			position.first += x_step;
			position.second += y_step;
			if(firstVisited.end() == firstVisited.find(position))
				firstVisited[position] = totalStepCounter;
		}
	 }


	position = { 0, 0 };
	int closest{ -1 };
	totalStepCounter = 0;
	std::map<coord, int> intersections;

	for (std::string element : secondLine) {
		int step;
		initStep(element, x_step, y_step, step);

		for (int idx = 0; idx < step; ++idx) {
			++totalStepCounter;
			position.first += x_step;
			position.second += y_step;
			if (firstVisited.end() != firstVisited.find(position) && intersections.end() == intersections.find(position))
			{
				intersections[position] = firstVisited[position] + totalStepCounter;
			}
			/*if (firstVisited.end() != firstVisited.find(position)) {
				if (abs(position.first) + abs(position.second) < closest || -1 == closest) {
					closest = abs(position.first) + abs(position.second);
				}
			}
			*/
		}
	}

	int smallest = -1;
	for (auto i : intersections) {
		if (i.second < smallest || -1 == smallest) smallest = i.second;
	}
	std::cout << "Szerintem: " << smallest;
	
}