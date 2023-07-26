#pragma once
#include "Animal.h"

class Bird : public Animal {
public:
	/** Default Constructor: Initializes default values for the Mammal. */
	Bird() = default;

	/**
	 * Constructor: Initializes data members of the Mammal and Animal.
	 * @param species The type of species of the animal (e.g hummingbird, Owl, Hawk, Eagle, ect...)
	 * @param age The age of the animal in years.
	 * @para type The type of bnimal which is bird.
	 * @param habitatType The type of habitat the animal lives in.
	 * @param feedingTime The time when the animal is feed in military time.
	 * @param name The name of the bird.
	 * @param wingSpan The measure in centimeters of the bird wing span.
	 * @param canFly The bool value to represent if the bird can or cannot fly.
	 * @param migrationStatus To show the migration status of the bird 
	 *		e.g (Migratory - changes location often, Non-Migatory - live in the same place year round)
	 */
	Bird(const std::string& species, int age, const std::string& type, const std::string& habitatType, 
		const std::string& feedingTime, std::string& name, double wingSpan, bool canFly, const std::string& migrationStatus);

	// Copy Constructor
	Bird(const Bird& bird);

	// Assignment operator
	Bird& operator=(const Bird& bird);

	/** Destructor: Responsible for cleaning up resources. */
	~Bird() = default;

	/** Virtual function to display information about the Bird. Overriden from Base class Animal */
	virtual void displayInfo() override;

	/** Getter method to return the wing span of a bird in centimeters. */
	double getWingSpan() const;

	/** Getter method to return if the bird can fly (true) or if the bird cannot fly (false). */
	bool getCanFly() const;

	/** Getter method to return if the bird is migratory type or non-migatory type. */
	std::string getMigrationStatus() const;

	/** Setter method to set the wing span of a bird in centimeters. */
	void setWingSpan(double wingSpan);

	/** Setter method to set if the bird can fly (true) or if the bird cannot fly (false). */
	void setCanFly(bool canFly);

	/** Setter method to set if the bird is migratory type or non-migatory type. */
	void setMigrationStatus(std::string migrationStatus);


private:
	double wingSpan_ = 0.0;
	bool canFly_ = false;
	std::string migrationStatus_ = " ";
};