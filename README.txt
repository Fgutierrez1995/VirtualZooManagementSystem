Project Idea: Virtual Zoo Management System

Description:
Create a Virtual Zoo Management System that allows users to manage different types of animals, including mammals, birds, and reptiles. The system should provide functionalities for adding new animals, displaying animal information, and feeding animals.

Classes:

Animal (Base Class):
Properties: name, age, type (mammal, bird, reptile), habitat type, feeding time
Methods: getters and setters for the properties, displayInfo() to display general information about the animal

Mammal (Derived Class):
Inherits from the Animal class
Additional Properties: fur color, number of legs, type of mammal (e.g., carnivore, herbivore, omnivore)
Additional Methods: displayInfo() to override the base class method and include mammal-specific information

Bird (Derived Class):
Inherits from the Animal class
Additional Properties: wingspan, can fly (boolean), migration status (e.g., migratory, non-migratory)
Additional Methods: displayInfo() to override the base class method and include bird-specific information

Reptile (Derived Class):
Inherits from the Animal class
Additional Properties: scale color, preferred temperature range, type of reptile (e.g., snake, turtle, lizard)
Additional Methods: displayInfo() to override the base class method and include reptile-specific information

Zookeeper:
Properties: name, age, list of animals under their care (store pointers to Animal objects)
Methods: feedAnimals() to feed all the animals under the zookeeper's care

Zoo:
Properties: list of all animals in the zoo (store pointers to Animal objects)
Methods: addAnimal() to add a new animal to the zoo, displayAllAnimals() to display information about all animals in the zoo, simulateActivities() to simulate activities for each animal based on its type.
Additional Enhancements:

Implement input validation to handle invalid user inputs and prevent crashes.
Add functionalities for removing animals from the zoo and updating animal information.


