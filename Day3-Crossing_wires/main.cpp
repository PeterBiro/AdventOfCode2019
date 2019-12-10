#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
}