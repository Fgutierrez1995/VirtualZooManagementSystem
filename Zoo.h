#pragma once
#include "Animal.h"
#include "Mammal.h"
#include "Reptile.h"
#include "Bird.h"
#include <vector>
#include <memory>
#include <algorithm>

// Forward declaration of Zookeeper class
class Zookeeper;

/**
 * @brief The Zoo class represents a zoo with a collection of animals and zookeepers.
 * It allows adding and removing animals, managing zookeepers, and displaying information about the zoo's contents.
 */
class Zoo {
public:
	/* Default Constructor */
	Zoo() = default;

	/* Default Destructor */
	~Zoo() = default;

	/* Method to add a Zookeeper to the Zoo */
	void addZooKeeper(std::unique_ptr<Zookeeper> zookeeper);
	
	/* Method to create a Mammal object and return the object. This method will be called in the addAnimals() method. */
	std::unique_ptr<Mammal> addMammal();

	/* Method to create a Bird object and return the object. This method will be called in the addAnimals() method. */
	std::unique_ptr<Bird> addBird();

	/* Method to create a Mammal object and return the object. This method will be called in the addAnimals() method. */
	std::unique_ptr<Reptile> addReptile();

	/* Method to add an Animal to the Zoo */
	void addAnimal();

	/* Method to remove an animal from the Zoo 
	* @param name This will be the name of the animal.
	* @param species This will be the species of the animal (e.g Bear, Monkey, Owl, Lion, ect..)
	*/
	void removeAnimal(const std::string& name, const std::string& species);

	/* Method to notify zookeeper to remove its an animal from the their care.
	* @param name This will be the name of the animal.
	* @param species This will be the species of the animal (e.g Bear, Monkey, Owl, Lion, ect..)
	*/
	void notifyZookeepersForAnimalRemoval(const std::string& name, const std::string& species);

	/* Method returns the zooInventory_ vector */ 
	const std::vector<std::shared_ptr<Animal>>& getZooInventory() const;

	/* Method returns the zookeepers_ vector */
	const std::vector<std::unique_ptr<Zookeeper>>& getZooKeepers() const;

	/* Static method to sort the inventory by type (e.g mammal, bird, or reptile) */
	static bool compareType(const std::shared_ptr<Animal>& animal1, const std::shared_ptr<Animal>& animal2);

	/* Method to display all the animals in the Zoo */
	void displayAnimals();

	/* Method to display the pointer addresses for each address */
	void displayAddress();

	/**
	 * @brief Method to add animals to the zookeeper in the zookeepers_ vector.
	 * @param name The name of the zookeeper.
	 * This method associates specific animals with a zookeeper for care.
	 */
	void setZookeepersAnimals(const std::string& name);

	/**
	 * @brief Method to display the animals under the care of a specific zookeeper.
	 * @param name The name of the zookeeper.
	 * This method shows the animals that a particular zookeeper is responsible for.
	 */
	void displayZookeepersAnimalsByEmployee(const std::string& name);

	/**
	 * @brief Method to tell zookeepers to feed their animals.
	 * @param name The name of the zookeeper.
	 * This method shows the animals that a particular zookeeper is responsible for and if they have been feed.
	 */

	void zookeeperFeedAnimals(const std::string& name);

private:
	std::vector<std::shared_ptr<Animal>> zooInventory_;
	std::vector<std::unique_ptr<Zookeeper>> zookeepers_;
};