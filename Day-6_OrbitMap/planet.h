#pragma once
#include <string>
#include <vector>
#include <memory>

class PLANET
{
public:
	PLANET() = delete;
	PLANET(std::string, std::shared_ptr <PLANET>);
	PLANET(std::string);

	int getComDistance() const;
	void addNewOrbitingPlanet(std::shared_ptr <PLANET>);
	std::shared_ptr <PLANET> getOrbitCenter() const;
	std::vector <std::shared_ptr <PLANET>> getOrbitingPlanets() const;
	std::string getName();


private:
	std::string mName;
	int mComDistance;
	std::shared_ptr <PLANET> mOrbitCenter;
	std::vector <std::shared_ptr <PLANET>> mOrbitedBy;

};

