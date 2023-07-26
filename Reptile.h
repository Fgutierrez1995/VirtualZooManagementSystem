#pragma once
#include "Animal.h"

class Reptile : public Animal {

public:
	/** Default Constructor: Initializes default values for the Mammal. */
	Reptile() = default;

	/**
	 * Constructor: Initializes data members of the Reptile and Animal.
	 * @param species The type of species of the animal (e.g copperhead, gecko, sea turtle, ect..)
	 * @param age The age of the animal in years.
	 * @param type The type of animal which is Reptile
	 * @param habitatType The type of habitat the animal lives in.
	 * @param feedingTime The time when the animal is feed in military time.
	 * @param name The name of the reptile.
	 * @param color The scale color of the reptile.
	 * @param temp The perferred temperature for the reptile;
	 * @param repType The type of the reptile (e.g. snake, turtle, lizard)
	 */
	Reptile(const std::string& species, int age, const std::string& type, const std::string& habitatType,
		const std::string& feedingTime, const std::string& name, const std::string& color, int temp, const std::string& repType);

	// Copy Constructor
	Reptile(const Reptile& reptile);

	// Assignment operator
	Reptile& operator=(const Reptile& reptile);

	/** Destructor: Responsible for cleaning up resources. */
	~Reptile() = default;

	/** Virtual function to display information about the Reptile. Overriden from Base class Animal */
	virtual void displayInfo() override;

	/** Getter method to return the color of the reptile. */
	std::string getScaleColor() const;

	/** Getter method to return the perferred temperature for the reptile. */
	int getTemperature() const;

	/** Getter method to return the type of the reptile (e.g. snake, turtle, lizard) */
	std::string getReptileType() const;

	/** Setter method to set the color of the reptile. */
	void setColor(std::string color);

	/** Setter method to set the perferred temperature for the reptile. */
	void setTemperature(int temp);

	/** Setter method to set the type of the reptile (e.g. snake, turtle, lizard) */
	void setReptileType(std::string type);

private:
	std::string scaleColor_ = " ";
	int perferredTempRange_ = 0;
	std::string reptileType_ = " ";
};