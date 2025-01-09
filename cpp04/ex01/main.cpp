/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:49 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 10:19:18 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"


int main()
{
	// std::cout << std::endl;
	// const Animal* meta = new Animal();
	// std::cout << std::endl;

	// Dog* j = new Dog();
	// std::cout << std::endl;

	// const Animal* i = new Cat();
	// std::cout << std::endl;


	// std::string idea = j->getIdea(0);
	// std::cout << "idea: " << idea << std::endl;
	// std::cout << std::endl;
	
	// j->setIdea(0,"I like bones");
	// idea = j->getIdea(0);
	// std::cout << "New idea: " << idea << std::endl;
	// std::cout << std::endl;

	// Dog new_dog(*j);
	// std::cout << std::endl;

	// idea = new_dog.getIdea(0);
	// std::cout << "idea: " << idea << std::endl;
	// std::cout << std::endl;

	// delete j;
	// std::cout << std::endl;
	
	// idea = new_dog.getIdea(0);
	// std::cout << "idea: " << idea << std::endl;
	// std::cout << std::endl;
	
	// delete meta;
	// std::cout << std::endl;
	
	// delete i;
	// std::cout << std::endl;

	const int arraySize = 10;
    Animal* animals[arraySize * 2];

    // Create 10 dogs
    for (int i = 0; i < arraySize; i++) {
        animals[i] = new Dog();
    }

    // Create 10 cats
    for (int i = arraySize; i < arraySize * 2; i++) {
        animals[i] = new Cat();
    }

    std::cout << "\n--- Testing deep copy of brain ---\n" << std::endl;
    
    // Test deep copy by casting Animal* to Dog* to access brain methods
    Dog* dog1 = dynamic_cast<Dog*>(animals[0]);
    Dog* dog2 = dynamic_cast<Dog*>(animals[1]);
    
    if (dog1 && dog2) {  // Check if cast was successful
        // Set an idea in dog1
        dog1->setIdea(0, "I am the original dog!");
        
        // Make dog2 a copy of dog1
        *dog2 = *dog1;
        
        // Show they have the same idea
        std::cout << "Dog1's idea: " << dog1->getIdea(0) << std::endl;
        std::cout << "Dog2's idea: " << dog2->getIdea(0) << std::endl;
        
        // Prove they are separate by changing dog1's idea
        dog1->setIdea(0, "I changed my mind!");
        
        std::cout << "\nAfter changing dog1's idea:" << std::endl;
        std::cout << "Dog1's idea: " << dog1->getIdea(0) << std::endl;
        std::cout << "Dog2's idea: " << dog2->getIdea(0) << std::endl;
        
   }

    std::cout << "\n--- Deleting all animals ---\n" << std::endl;
    // Delete all animals
    for (int i = 0; i < arraySize * 2; i++) {
        delete animals[i];
        std::cout << std::endl;
    }

    return 0;
}
