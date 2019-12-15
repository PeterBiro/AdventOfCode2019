#include "planet.h"

PLANET::PLANET(std::string aName) :
	mName{ aName },
	mOrbitCenter{ nullptr },
	mComDistance{ 0 }
{}

PLANET::PLANET(std::string aName, std::shared_ptr <PLANET> aOrbitCenter) :
	mName{ aName },
	mOrbitCenter{ aOrbitCenter },
	mComDistance{ aOrbitCenter->getComDistance()+1 }
{}

int PLANET::getComDistance() const { return mComDistance; }
std::shared_ptr <PLANET> PLANET::getOrbitCenter() const { return mOrbitCenter; }
std::vector <std::shared_ptr <PLANET>> PLANET::getOrbitingPlanets() const { return mOrbitedBy; }
void PLANET::addNewOrbitingPlanet(std::shared_ptr <PLANET> aPlanet) {
	mOrbitedBy.push_back(aPlanet);
}
std::string PLANET::getName() { return mName; }