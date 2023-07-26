#pragma once
#include "Animal.h"

class Mammal : public Animal {
public:
	/** Default Constructor: Initializes default values for the Mammal. */
	Mammal() = default;

	/**
	 * Constructor: Initializes data members of the Mammal and Animal.
	 * @param species The type of species of the animal (e.g Brown Bear, Monkey, Gorilla, Lion, ..ect)
	 * @param age The age of the animal in years.
	 * @param type The type of animal which is always Mammal
	 * @param habitatType The type of habitat the animal lives in.
	 * @param feedingTime The time when the animal is feed in military time.
	 * @param name The name of the mammal.
	 * @param furColor The color of the fur of the mammal.
	 * @param numOflegs The number of legs the mammal has.
	 * @param mammalType The type of the mammal (e.g carnivore, herbivore, omnivore)
	 * 
	 */
	Mammal(const std::string& species, int age, const std::string& type, const std::string& habitatType, const std::string& feedingTime, const std::string& name, const std::string& furColor, int numOflegs, const std::string& mammalType);

	// Copy Constructor
	Mammal(const Mammal& mammal);

	// Assignment operator
	Mammal& operator=(const Mammal& mammal);

	/** Destructor: Responsible for cleaning up resources. */
	~Mammal() = default;

	/** Virtual function to display information about the Mammal. Overriden from Base class Animal */
	virtual void displayInfo() override;

	/** Getter method to return the fur color of the mammal. */
	std::string getFurColor() const;

	/** Getter method to return the number of legs of the mammal. */
	int getNumOfLegs() const;

	/** Getter method to return the type of the mammal (e.g carnivore, herbivore, omnivore). */
	std::string getMammalType() const;

	/** Setter method to set the fur color of the mammal. */
	void setFurColor(std::string furColor);

	/** Setter method to set the number of legs of the mammal. */
	void setNumOfLegs(int numOfLegs);

	/** Setter method to set the type of the mammal (e.g carnivore, herbivore, omnivore). */
	void setMammalType(std::string mammalType);


private:
	std::string furColor_ = " ";
	int numOfLegs_ = 0;
	std::string mammalType_ = " ";

};