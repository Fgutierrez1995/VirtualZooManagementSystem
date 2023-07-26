#pragma once
#include <string>
#include <iostream>

class Animal {
public:
	/** Default Constructor: Initializes default values for the animal. */
	Animal() = default;

	/**
	 * Constructor: Initializes data members of the animal.
	 * @param species The type of species of the animal (e.g hummingbird, monkey, copperhead, ect..)
	 * @param age The age of the animal in years.
	 * @param type The generic classification type of the animal (e.g Mammal, Bird, Reptile)
	 * @param habitatType The type of habitat the animal lives in.
	 * @param feedingTime The time when the animal is feed in military time. 
	 * @param name The name of the animal.
	 */
	Animal(const std::string& species, int age, const std::string& type, const std::string& habitatType, const std::string& feedingTime, const std::string& name);

	/** Destructor: Responsible for cleaning up resources. */
	~Animal() = default;

	/** Virtual function to display information about the animal. */
	virtual void displayInfo();

	/** Getter method to return the species of the animal. */
	std::string getSpecies() const;

	/** Getter method to return the age of the animal. */
	int getAge() const;

	/** Getter method to return the type/species of the animal. */
	std::string getType() const;

	/** Getter method to return the habitat type of the animal. */
	std::string getHabitatType() const;

	/** Getter method to return the feeding time of the animal in minutes. */
	std::string getFeedingTime() const;

	/** Getter method to return the name of the animal */
	std::string getName() const;

	/** Setter method to assign a value to the species of the animal. */
	void setSpecies(std::string species);

	/** Setter method to assign a value to the age of the animal. */
	void setAge(int age);

	/** Setter method to assign a value to the type/species of the animal. */
	void setType(std::string type);

	/** Setter method to assign a value to the habitat type of the animal. */
	void setHabitatType(std::string habitatType);

	/** Setter method to assign a value to the feeding time for the animal in military time. */
	void setFeedingTime(std::string feedingTime);

	/** Setter method to assign a value to the name of the animal */
	void setName(std::string name);

private:
	std::string species_ = " ";
	int age_ = 0;
	std::string type_ = " ";
	std::string habitatType_ = " ";
	std::string feedingTime_ = " ";
	std::string name_ = " ";
};