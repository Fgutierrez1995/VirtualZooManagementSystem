#include "Zookeeper.h"

// Constructor

Zookeeper::Zookeeper(const std::string& name, int age) : name_(name), age_(age) {}


/* Method to set the animals in care for the zookeeper. */

void Zookeeper::setAnimals(const std::vector<std::shared_ptr<Animal>>& zooInventory) {
	// clear any previous Animal objects
	animalsInCare_.clear();

	// Receive the animal type from the User
	std::string animalType;
	std::cout << "Enter the Animal type for the zookeeper " << name_ << " to manage: ";
	std::cin >> animalType;
	// Convert the input to lowercase for case-insensitive comparison
	std::transform(begin(animalType), end(animalType), begin(animalType), [](char c) { return std::tolower(c); });

	bool foundAnimals = false; // Flag to check if any animals were added

	for (const auto& animal : zooInventory) {
		std::string type = animal->getType();
		// Convert the input to lowercase for case-insensitive comparison
		std::transform(begin(type), end(type), begin(type), [](char c) { return std::tolower(c); });
		
		if (type == animalType) {
			// copy the shared_ptr<Animal> to the zookeepers animalsInCare_
			animalsInCare_.push_back(animal);
			foundAnimals = true;
		}
	}

	if (!foundAnimals) {
		std::cout << "Animal type not found." << std::endl;
	}
}

/* Displays the animals information in the zookeeper care */

void Zookeeper::displayAnimals() {
	std::cout << "Employee " << name_ << " animals in their care: " << std::endl;
	for (const auto& animal : animalsInCare_) {
		animal->displayInfo();
		std::cout << std::endl;
	}
}

/* Test method to check and make sure the object addresses are shared */

void Zookeeper::displayAddress() {
	for (const auto& animal : animalsInCare_) {
		std::cout << "Address of Animal in animalsInCare_: " << animal.get() << std::endl;
	}
}

/* This method return a bool value depending if the Zookeeper did or did not feed the animals */

bool Zookeeper::feedAnimals() {
	if (!animalsInCare_.empty()) {
		std::cout << "All Animals in your care name and feed time." << std::endl;
		for (const auto& animal : animalsInCare_) {
			std::cout << "Animal Species: " << animal->getSpecies() << std::endl;
			std::cout << "Animal Name: " << animal->getName() << std::endl;
			std::cout << "Feeding Time: " << animal->getFeedingTime() << std::endl;
		}
		bool animalsFeed = false;
		std::string choice;
		do {
			std::cout << "Are all the animals feed? Please enter 'Yes' or 'No'" << std::endl;
			std::cin >> choice;

			// Convert the input to lowercase for case-insensitive comparion
			std::transform(begin(choice), end(choice), begin(choice), [](char c) { return std::tolower(c); });

			if (choice == "yes") {
				animalsFeed = true;
			}
			else if (choice == "no") {
				animalsFeed = false;
			}
			else {
				std::cout << "Invalid option entered." << std::endl;
			}
		} while (choice != "yes" && choice != "no");

		if (animalsFeed) {
			std::cout << "All animals have been feed." << std::endl;
		}
		else {
			std::cout << "Please feed the animal at the required time." << std::endl;
		}

		return animalsFeed;
	}
	std::cout << "Zookeeper has no animals in their care." << std::endl;
	return false;
}

// Method is used to remove a animal from the zookeepers care. 

void Zookeeper::removeAnimalFromCare(const std::string& name, const std::string& species) {
	std::string lowercaseName = name;
	std::string lowercaseSpecies = species;
	std::transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);
	std::transform(lowercaseSpecies.begin(), lowercaseSpecies.end(), lowercaseSpecies.begin(), ::tolower);

	for (auto it = animalsInCare_.begin(); it != animalsInCare_.end();) {
		std::string animalName = (*it)->getName();
		std::string animalSpecies = (*it)->getSpecies();

		std::transform(animalName.begin(), animalName.end(), animalName.begin(), ::tolower);
		std::transform(animalSpecies.begin(), animalSpecies.end(), animalSpecies.begin(), ::tolower);

		if (animalName == lowercaseName && animalSpecies == lowercaseSpecies) {

			it = animalsInCare_.erase(it);
			std::cout << "Sucessfully removed Animal from Zookeeper care" << std::endl;
			return;
		}
		else {
			++it;
		}
	}
	std::cout << name_ << " zookeeper has no animal by the name/species of " << name << " or " << species << ".\n";
}

// Method to return zookeepers name. 

std::string Zookeeper::getZookeeperName() const { return name_; }