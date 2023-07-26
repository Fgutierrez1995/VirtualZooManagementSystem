#include "Reptile.h"

/* Constructor */

Reptile::Reptile(const std::string& species, int age, const std::string& type, const std::string& habitatType,
	const std::string& feedingTime, const std::string& name, const std::string& color, int temp, const std::string& repType) :
	Animal(species, age, type, habitatType, feedingTime, name), scaleColor_(color), perferredTempRange_(temp), reptileType_(repType) {}

/* Copy Constructor */

Reptile::Reptile(const Reptile& reptile) : Animal(reptile) {
	scaleColor_ = reptile.scaleColor_;
	perferredTempRange_ = reptile.perferredTempRange_;
	reptileType_ = reptile.reptileType_;
}

/* Overloaded assignment operator */

Reptile& Reptile::operator=(const Reptile& reptile) {
	Reptile::setSpecies(reptile.getSpecies());
	Reptile::setAge(reptile.getAge());
	Reptile::setType(reptile.getType());
	Reptile::setHabitatType(reptile.getHabitatType());
	Reptile::setFeedingTime(reptile.getFeedingTime());
	Reptile::setName(reptile.getName());
	scaleColor_ = reptile.scaleColor_;
	perferredTempRange_ = reptile.perferredTempRange_;
	reptileType_ = reptile.reptileType_;

	return *this;
}

/* Display Reptile Information */

void Reptile::displayInfo() {
	std::cout << "Reptile Species: " << Reptile ::getSpecies() << std::endl;
	std::cout << "Reptile Age: " << Reptile::getAge() << std::endl;
	std::cout << "Reptile Habitat Type: " << Reptile::getHabitatType() << std::endl;
	std::cout << "Reptile Feeding Time: " << Reptile::getFeedingTime() << std::endl;
	std::cout << "Reptile Name: " << Reptile::getName() << std::endl;
	std::cout << "Reptile Scale Color: " << scaleColor_ << std::endl;
	std::cout << "Reptile Perferred Temperature: " << perferredTempRange_ << std::endl;
	std::cout << "Type of Reptile: " << reptileType_ << std::endl;
}

/** Getter Methods  */

std::string Reptile::getScaleColor() const { return scaleColor_; }
int Reptile::getTemperature() const { return perferredTempRange_; }
std::string Reptile::getReptileType() const { return reptileType_; }

/** Setter Methods */

void Reptile::setColor(std::string color) { scaleColor_ = color; }
void Reptile::setTemperature(int temp) { perferredTempRange_ = temp; }
void Reptile::setReptileType(std::string type) { reptileType_ = type; }