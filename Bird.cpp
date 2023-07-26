#include "Bird.h"

/* Constructor */ 
Bird::Bird(const std::string& species, int age, const std::string& type, const std::string& habitatType,
	const std::string& feedingTime, std::string& name, double wingSpan, bool canFly, const std::string& migrationStatus) :
	Animal(species, age, type, habitatType, feedingTime, name), wingSpan_(wingSpan), canFly_(canFly), migrationStatus_(migrationStatus) {}

/* Copy Constructor */
Bird::Bird(const Bird& bird) : Animal(bird) {
	wingSpan_ = bird.wingSpan_;
	canFly_ = bird.canFly_;
	migrationStatus_ = bird.migrationStatus_;
}

/* Assignment operator */
Bird& Bird::operator=(const Bird& bird) {
	Bird::setSpecies(bird.getSpecies());
	Bird::setAge(bird.getAge());
	Bird::setType(bird.getType());
	Bird::setHabitatType(bird.getHabitatType());
	Bird::setFeedingTime(bird.getFeedingTime());
	Bird::setName(bird.getName());
	wingSpan_ = bird.wingSpan_;
	canFly_ = bird.canFly_;
	migrationStatus_ = bird.migrationStatus_;

	return *this;
}

/** Virtual function to display information about the Bird. Overriden from Base class Animal */
void Bird::displayInfo() {
	std::cout << "Bird Species: " << Bird::getSpecies() << std::endl;
	std::cout << "Bird Age: " << Bird::getAge() << std::endl;
	std::cout << "Bird Habitat Type: " << Bird::getHabitatType() << std::endl;
	std::cout << "Bird Feeding Time: " << Bird::getFeedingTime() << std::endl;
	std::cout << "Bird Name: " << Bird::getName() << std::endl;
	std::cout << "Bird Wing Span Centimeters: " << wingSpan_ << std::endl;
	std::cout << "Bird " << (canFly_ ? "Can Fly. " : "Cannot Fly. ") << std::endl;
	std::cout << "Bird Migration Status: " << migrationStatus_ << std::endl;
}

/** Getter method */
double Bird::getWingSpan() const { return wingSpan_; }
bool Bird::getCanFly() const { return canFly_; }
std::string Bird::getMigrationStatus() const { return migrationStatus_; }

/** Setter method */
void Bird::setWingSpan(double wingSpan) { wingSpan_ = wingSpan; }
void Bird::setCanFly(bool canFly) { canFly_ = canFly; }
void Bird::setMigrationStatus(std::string migrationStatus) { migrationStatus_ = migrationStatus; }