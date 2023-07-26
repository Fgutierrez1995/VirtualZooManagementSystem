#include "Mammal.h"

// Constructor

Mammal::Mammal(const std::string& species, int age, const std::string& type, const std::string& habitatType, const std::string& feedingTime, const std::string& name, const std::string& furColor, int numOflegs, const std::string& mammalType) :
	Animal(species, age, type, habitatType, feedingTime, name), furColor_(furColor), numOfLegs_(numOflegs), mammalType_(mammalType) {}

// Copy Constructor

Mammal::Mammal(const Mammal& mammal): Animal(mammal) {
	furColor_ = mammal.furColor_;
	numOfLegs_ = mammal.numOfLegs_;
	mammalType_ = mammal.mammalType_;
}

// Assignment operator
// Returns the copied Mammal object

Mammal& Mammal::operator=(const Mammal& mammal) {
	Mammal::setSpecies(mammal.getSpecies());
	Mammal::setAge(mammal.getAge());
	Mammal::setType(mammal.getType());
	Mammal::setHabitatType(mammal.getHabitatType());
	Mammal::setFeedingTime(mammal.getFeedingTime());
	Mammal::setName(mammal.getName());
	furColor_ = mammal.furColor_;
	numOfLegs_ = mammal.numOfLegs_;
	mammalType_ = mammal.mammalType_;

	return *this;
}

// Display information about the Mammal. Overriden from Base class Animal

void Mammal::displayInfo() {
	std::cout << "Mammal Species: " << Mammal::getSpecies() << std::endl;
	std::cout << "Mammal Age: " << Mammal::getAge() << std::endl;
	std::cout << "Mammal Habitat Type: " << Mammal::getHabitatType() << std::endl;
	std::cout << "Mammal Feeding Time: " << Mammal::getFeedingTime() << std::endl;
	std::cout << "Mammal Name: " << Mammal::getName() << std::endl;
	std::cout << "Mammal Fur Color: " << furColor_ << std::endl;
	std::cout << "Mammal Number of Legs: " << numOfLegs_ << std::endl;
	std::cout << "Type of Mammal: " << mammalType_ << std::endl;
}

// Getter Methods

std::string Mammal::getFurColor() const { return furColor_; }
int Mammal::getNumOfLegs() const { return numOfLegs_; }
std::string Mammal::getMammalType() const { return mammalType_; }

// Setter methods

void Mammal::setFurColor(std::string furColor) { furColor_ = furColor; }
void Mammal::setNumOfLegs(int numOfLegs) { numOfLegs_ = numOfLegs; }
void Mammal::setMammalType(std::string mammalType) { mammalType_ = mammalType;}

