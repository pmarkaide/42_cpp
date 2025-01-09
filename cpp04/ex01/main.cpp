/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:49 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 09:14:51 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"


int main(){

	const Animal* meta = new Animal();
	std::cout << std::endl;


	std::cout << std::endl;

	Dog* j = new Dog();
	std::cout << std::endl;

	const Animal* i = new Cat();
	std::cout << std::endl;


	std::string idea = j->getIdea(0);
	std::cout << "idea: " << idea << std::endl;
	std::cout << std::endl;
	
	j->setIdea(0,"I like bones");
	idea = j->getIdea(0);
	std::cout << "New idea: " << idea << std::endl;
	std::cout << std::endl;

	Dog new_dog(*j);
	std::cout << std::endl;

	idea = new_dog.getIdea(0);
	std::cout << "idea: " << idea << std::endl;
	std::cout << std::endl;

	delete j;
	std::cout << std::endl;
	
	idea = new_dog.getIdea(0);
	std::cout << "idea: " << idea << std::endl;
	std::cout << std::endl;
	
	
	delete meta;
	std::cout << std::endl;
	
	delete i;
	std::cout << std::endl;
	
	delete j;
	std::cout << std::endl;

	return 0;
}