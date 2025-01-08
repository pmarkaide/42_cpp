/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:05:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:19:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main(){

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

	return 0;

}