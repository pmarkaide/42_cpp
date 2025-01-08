/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:05:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:55:42 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main(){

	{
	const Animal* meta = new Animal();
	std::cout << std::endl;

	meta->makeSound();
	std::cout << std::endl;

	const Animal* j = new Dog();
	std::cout << std::endl;

	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << std::endl;
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;

	j->makeSound();
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	
	delete i;
	std::cout << std::endl;
	
	delete j;
	std::cout << std::endl;
	}
	{
	const WrongAnimal* meta = new WrongAnimal();
	std::cout << std::endl;

	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* i = new WrongCat();
	std::cout << std::endl;
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "Beware! WrongCat is gonna roar:" << std::endl;
	i->makeSound();
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	
	delete i;
	std::cout << std::endl;
	
	}

	return 0;

}