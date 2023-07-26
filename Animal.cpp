#include "Animal.h"

// Constructor: Initializes data members of the animal.

Animal::Animal(const std::string& species, int age, const std::string& type, const std::string& habitatType, const std::string& feedingTime, const std::string& name) :
	species_(species), age_(age), type_(type), habitatType_(habitatType), feedingTime_(feedingTime), name_(name) {}


// function to display information about the animal

void Animal::displayInfo() {
	std::cout << "Animal Species: " << species_ << std::endl;
	std::cout << "Animal Age: " << age_ << std::endl;
	std::cout << "Animal Type: " << type_ << std::endl;
	std::cout << "Animal Habitat Type: " << habitatType_ << std::endl;
	std::cout << "Animal Feeding Time: " << feedingTime_ << std::endl;
	std::cout << "Animal Name: " << name_ << std::endl;
}

/* Getter methods */

std::string Animal::getSpecies() const { return species_; }
int Animal::getAge() const { return age_; }
std::string Animal::getType() const { return type_; }
std::string Animal::getHabitatType() const { return habitatType_; }
std::string Animal::getFeedingTime() const { return feedingTime_; }
std::string Animal::getName() const { return name_; }


/** Setter methods */

void Animal::setSpecies(std::string species) { species_ = species; }
void Animal::setAge(int age) { age_ = age; }
void Animal::setType(std::string type) { type_ = type; }
void Animal::setHabitatType(std::string habitatType) { habitatType_ = habitatType; }
void Animal::setFeedingTime(std::string feedingTime) { feedingTime_ = feedingTime; }
void Animal::setName(std::string name) { name_ = name; }