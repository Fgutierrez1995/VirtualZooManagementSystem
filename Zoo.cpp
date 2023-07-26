#include "Zoo.h"
#include "Zookeeper.h"

// Method to add a Zookeeper to the zookeepers_ vector
void Zoo::addZooKeeper(std::unique_ptr<Zookeeper> zookeeper) {
	zookeepers_.push_back(std::move(zookeeper));
}

// Method to return the zookeepers_ vector
const std::vector<std::unique_ptr<Zookeeper>>& Zoo::getZooKeepers() const {
	return zookeepers_;
}

/* Method to read user inputs and return the created a Mammal object */

std::unique_ptr<Mammal> Zoo::addMammal() {
	std::string species, habitatType, feedingTime, name, furColor, mammalType;
	int age, numOfLegs;
	std::cout << "Enter the species type for the mammal: ";
	std::getline(std::cin, species);
	
	std::cout << "Enter the age of the mammal in years: ";
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

	std::cout << "Enter the habitat type of the mammal: ";
	std::getline(std::cin, habitatType);

	std::cout << "Enter the feeding time for the mammal: ";
	std::getline(std::cin, feedingTime);


	std::cout << "Enter the name of the mammal: ";
	std::getline(std::cin, name);

	std::cout << "Enter the fur color of the mammal: ";
	std::getline(std::cin, furColor);

	std::cout << "Enter the number of legs of the mammal: ";
	std::cin >> numOfLegs;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

	std::cout << "Enter the type of mammal (e.g carnivore, herbivore, omnivore): ";
	std::getline(std::cin, mammalType);

	return std::make_unique<Mammal>(species, age, "Mammal", habitatType, feedingTime, name, furColor, numOfLegs, mammalType);
		
}

/* Method to read user inputs and return the created a Bird object */

std::unique_ptr<Bird> Zoo::addBird() {
	std::string species, habitatType, feedTime, name, migrationStatus, choice;
	int age;
	double wingSpan;

	bool canFly;

	std::cout << "Enter the type of species of the bird: ";
	std::getline(std::cin, species);

	std::cout << "Enter the age of the bird in years: ";
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

	std::cout << "Enter the habitat type of the bird: ";
	std::getline(std::cin, habitatType);

	std::cout << "Enter the feeding time for the bird: ";
	std::getline(std::cin, feedTime);

	std::cout << "Enter the name of the bird: ";
	std::getline(std::cin, name);

	std::cout << "Enter the wing span of the bird in centimeters: ";
	std::cin >> wingSpan;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

	do {
		std::cout << "Enter 'Yes' or 'No' if the bird can fly: ";
		std::cin >> choice;
		// Convert choice to lower case for case sensitive comparison
		std::transform(begin(choice), end(choice), begin(choice), [](char c) { return std::tolower(c);  });
		if (choice == "yes") {
			canFly = true;
		}
		else if (choice == "no") {
			canFly = false;
		}
		else {
			std::cout << "Invalid choice entered." << std::endl;
		}
	} while (choice != "yes" && choice != "no");

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character
	std::cout << "Enter the migration status of the bird. e.g (Migratory - changes location often, Non-Migatory - live in the same place year round): ";
	std::getline(std::cin, migrationStatus);

	return std::make_unique<Bird>(species, age, "Bird", habitatType, feedTime, name, wingSpan, canFly, migrationStatus);
}

/* Method to read user inputs and return the created a Reptile object */

std::unique_ptr<Reptile> Zoo::addReptile() {
	std::string species, habitatType, feedingTime, name, color, repType;
	int age, temp;

	std::cout << "Enter the type of species of the reptile: ";
	std::getline(std::cin, species);

	std::cout << "Enter the age of the reptile: ";
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

	std::cout << "Enter the habitat type of the reptile: ";
	std::getline(std::cin, habitatType);

	std::cout << "Enter the feeding time of the reptile: ";
	std::getline(std::cin, feedingTime);

	std::cout << "Enter the name of the reptile: ";
	std::getline(std::cin, name);

	std::cout << "Enter the color of the reptile: ";
	std::getline(std::cin, color);

	std::cout << "Enter the perfered temp for the reptiles environment: ";
	std::cin >> temp;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

	std::cout << "Enter the type of reptile (e.g. snake, turtle, lizard): ";
	std::getline(std::cin, repType);

	return std::make_unique<Reptile>(species, age, "Reptile", habitatType, name, feedingTime, color, temp, repType);
}

void Zoo::addAnimal() {
	int choice;
	bool finished = false;
	do {
		system("cls"); // Clears the console
		std::cout << "Please enter what type of animal to add. " << std::endl;
		std::cout << "1. Mammal, 2. Bird, 3. Reptile, or 0 to quit" << std::endl;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character
		switch (choice) {
		case 1: {
			std::unique_ptr<Mammal> mammal = addMammal();
			if (mammal != nullptr) {
				zooInventory_.push_back(std::move(mammal));
			}
			break;
		}

		case 2: {
			std::unique_ptr<Bird> bird = addBird();
			if (bird != nullptr) {
				zooInventory_.push_back(std::move(bird));
			}
			break;
		}

		case 3: {
			std::unique_ptr<Reptile> reptile = addReptile();
			if (reptile != nullptr) {
				zooInventory_.push_back(std::move(reptile));
			}
			break;
		}
		case 0: {
			finished = true;
			break;
		}
	
		default:
			std::cout << "Invalid option. Try agian." << std::endl;
			break;
		}
	} while (!finished);
}

/* This method will be called to remove a animal from the Zoo Inventory. 
*  Name will be used for the animals name.
*  Type will be used for the animals type (e.g mammal, bird or reptile).
*  This will iterate through the zooIventory_ and compare the 
*  name of each animal and the animal type until a match.
*/
void Zoo::removeAnimal(const std::string& name, const std::string& species) {
	std::string lowercaseName = name;
	std::string lowercaseSpecies = species;
	std::transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);
	std::transform(lowercaseSpecies.begin(), lowercaseSpecies.end(), lowercaseSpecies.begin(), ::tolower);

	for (auto it = zooInventory_.begin(); it != zooInventory_.end();) {
		std::string animalName = (*it)->getName();
		std::string animalSpecies = (*it)->getSpecies();
		
		std::transform(animalName.begin(), animalName.end(), animalName.begin(), ::tolower);
		std::transform(animalSpecies.begin(), animalSpecies.end(), animalSpecies.begin(), ::tolower);

		if (animalName == lowercaseName && animalSpecies == lowercaseSpecies) {
			// Notify the corresponding Zookeeper about the remove of the animal
			notifyZookeepersForAnimalRemoval(name, species);

			it = zooInventory_.erase(it);
			std::cout << "Sucessfully removed Animal from Zoo" << std::endl;
			return;
		} else {
			++it;
		}
	}
	std::cout << "No animal was found with name " << name << " and species " << species << ".\n";

}

/* This helper function iterates through the zookeepers_ vector and notifys each zookeeper
*  to remove the animal in care that matches the parameters name and species.
*  Zookeeper will call its class method removeAnimalFromCare.
*/
void Zoo::notifyZookeepersForAnimalRemoval(const std::string& name, const std::string& species) {
	for (auto& zookeeper : zookeepers_) {
		zookeeper->removeAnimalFromCare(name, species);
	}
}


/* Method to sort the inventory by species (e.g mammal, bird, or reptile)
*  This method will be used to sort the zoo inventory vector "zooIventory_"
*/
bool Zoo::compareType(const std::shared_ptr<Animal>& animal1, const std::shared_ptr<Animal>& animal2) {
	return animal1->getType() < animal2->getType();
}

void Zoo::displayAnimals() {
	std::sort(zooInventory_.begin(), zooInventory_.end(), compareType);
	std::cout << "Zoo Inventory of animals: " << std::endl;
	for (const auto& animal : zooInventory_) {
		animal->displayInfo();
		std::cout << std::endl;
	}
}

const std::vector<std::shared_ptr<Animal>>& Zoo::getZooInventory() const {
	return zooInventory_;
}

void Zoo::displayAddress() {

	for (const auto& animal : zooInventory_) {
		std::cout << "Address of Animal in zooInventory_: " << animal.get() << std::endl;
	}
}

void Zoo::setZookeepersAnimals(const std::string& name) {
	// bool value to see if name is found.
	bool foundMatch = false;
	// If zookeepers vector is not empty
	if (!zookeepers_.empty()) {
		for (auto& zookeeper : zookeepers_) {
			// Check if the zookeeper name matches parameter name
			if (zookeeper->getZookeeperName() == name) {
				// Found match
				foundMatch = true;
				// If match, call zookeeper method setAnimals
				zookeeper->setAnimals(zooInventory_);
			}
		}
	}
	else {
		// If zookeepers_ vector is empty
		std::cout << "Zoo currently no zookeepers" << std::endl;
	}
	// If no match was found
	if (!foundMatch) {
		std::cout << "No zookeeper found with the name: " << name << std::endl;
	}
}

void Zoo::displayZookeepersAnimalsByEmployee(const std::string& name) {
	// If zookeepers vector is not empty
	if (!zookeepers_.empty()) {
		for (auto& zookeeper : zookeepers_) {
			// Check if the zookeeper name matches parameter name
			if (zookeeper->getZookeeperName() == name) {
				// If match, call zookeeper method setAnimals
				zookeeper->displayAnimals();
			}
		}
	}
	else {
		// If zookeepers_ vector is empty
		std::cout << "No Zookeepers Employees found" << std::endl;
	}
}

void Zoo::zookeeperFeedAnimals(const std::string& name) {
	// If zookeepers vector is not empty
	if (!zookeepers_.empty()) {
		for (auto& zookeeper : zookeepers_) {
			// Check if the zookeeper name matches parameter name
			if (zookeeper->getZookeeperName() == name) {
				// If match, call zookeeper method setAnimals
				zookeeper->feedAnimals();
			}
		}
	}
	else {
		// If zookeepers_ vector is empty
		std::cout << "No Zookeepers Employees found" << std::endl;
	}
}