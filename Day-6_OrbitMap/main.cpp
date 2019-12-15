#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

#include "planet.h"

std::shared_ptr <PLANET> theUniverse(new PLANET("COM"));
std::map <std::string, std::shared_ptr <PLANET>> universeRegister;

auto readInput(const char* fileName) {
	std::vector <std::pair <std::string, std::string>> planetPairs;
	std::ifstream inputFile(fileName);
	std::string line;
	
	while (inputFile >> line) {
		planetPairs.push_back(std::make_pair(line.substr(0, 3), line.substr(4, 3)));
	}
	return planetPairs;
}

void setupTheUniverse() {
	auto planetConnections = readInput("input_1.txt");
	universeRegister.emplace("COM", theUniverse);

	std::queue <std::string> freshPlanets;
	freshPlanets.push("COM");
	while (!freshPlanets.empty()) {
		std::string planetName = freshPlanets.front();
		freshPlanets.pop();
		for (auto connection : planetConnections) {
			if (connection.first == planetName) {
				universeRegister.emplace(connection.second, new PLANET(connection.second, universeRegister[planetName]));
				universeRegister[planetName]->addNewOrbitingPlanet(universeRegister[connection.second]);
				freshPlanets.push(connection.second);
			}
		}
	}
}

auto simpleRouteFromTo(std::string from, std::string to) {
	std::shared_ptr <PLANET> planet = universeRegister[from];
	std::stack <std::string> result;
	result.push(from);
	while (planet->getName() != to) {
		planet = planet->getOrbitCenter();
		result.push(planet->getName());
	}
	return result;
}

int main() {
	int task = 2;

	setupTheUniverse();

	if (1 == task) {
		int n = 0;
		for (auto planet : universeRegister) {
			n += planet.second->getComDistance();
		}
		std::cout << n;
	}

	if (2 == task ) {

		auto SAN_parents = simpleRouteFromTo("SAN", "COM");
		auto YOU_parents = simpleRouteFromTo("YOU", "COM");

		while (SAN_parents.top() == YOU_parents.top() || SAN_parents.empty() || YOU_parents.empty()) {
			SAN_parents.pop();
			YOU_parents.pop();
		}
		std::cout << SAN_parents.size() + YOU_parents.size() - 2;
	}

}