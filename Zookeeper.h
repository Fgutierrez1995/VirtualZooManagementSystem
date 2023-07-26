#pragma once
#include "Zoo.h"
#include <vector>
#include <algorithm>


class Zookeeper {
public:
	/* Default Constructor */
	Zookeeper() = default;

	/**
	 * @brief Constructor: Initializes data members of the zookeeper.
	 * @param name The name of the zookeeper.
	 * @param age The age of the zookeeper.
	 */
	Zookeeper(const std::string& name, int age);

	/* Destructor */
	~Zookeeper() = default;

	/**
	  * @brief Method to set the animals in care for the zookeeper.
	  * This method associates specific animal objects with the zookeeper for care.
	  * @param zooInventory The zoo's inventory of animals (result of zooObject.getZooInventory()).
	  */
	void setAnimals(const std::vector<std::shared_ptr<Animal>>& zooInventory);

	/* Method displays the animals in the animalsInCare_ by the dynamic type calling animal::displayInfo()*/
	void displayAnimals();

	/* Test method to check and make sure the object addresses are shared */
	void displayAddress();

	/* Method to check if the animals in the zookeeper care have been feed. */
	bool feedAnimals();

	/* Method is used to remove a animal from the Zookeepers care. 
	*  @param name The name of the animal.
	*  @param species the type of species of the animal (e.g Bear, Lion, Owl, Gecko, ect..)
	*/
	void removeAnimalFromCare(const std::string& name, const std::string& species);

	/** Getter method to return name of the zookeeper. */
	std::string getZookeeperName() const;

private:
	std::string name_ = "";
	int age_ = 0;
	std::vector<std::shared_ptr<Animal>> animalsInCare_;
};