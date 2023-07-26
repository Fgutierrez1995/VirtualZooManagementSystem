#include "Zoo.h"
#include "Zookeeper.h"
#include "memory"
#include <iostream>

int main() {
	// Zoo object
	Zoo zoo;

	// Zookeepers added to the zoo employee vector.
	zoo.addZooKeeper(std::make_unique<Zookeeper>("Bob", 25));
	zoo.addZooKeeper(std::make_unique<Zookeeper>("Kathy", 28));
	zoo.addZooKeeper(std::make_unique<Zookeeper>("Ross", 33));

	// Adding animals to the zoo inventory.
	zoo.addAnimal();

	// Setting animals to the zookeepers care. 
	zoo.setZookeepersAnimals("Bob");
	zoo.setZookeepersAnimals("Kathy");
	zoo.setZookeepersAnimals("Ross");

	// Displaying the animals in the care of the zookeepers.
	zoo.displayZookeepersAnimalsByEmployee("Bob");
	zoo.displayZookeepersAnimalsByEmployee("Kathy");
	zoo.displayZookeepersAnimalsByEmployee("Ross");

	// Check zookeeper employees feed their animals.
	zoo.zookeeperFeedAnimals("Bob");
	zoo.zookeeperFeedAnimals("Kathy");
	zoo.zookeeperFeedAnimals("Ross");

	// Remove a animal from the zoo and zookeepers care
	zoo.removeAnimal("Zumba", "Lion");

	// Displays all animals in the zoo.
	zoo.displayAnimals();
	
}