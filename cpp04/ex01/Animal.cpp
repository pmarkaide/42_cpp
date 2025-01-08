/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:10 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 14:31:12 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Animal.hpp"

Animal::Animal(): type_("Animal"){
	std::cout << "Animal constructor called" << std::endl;	
}

Animal::Animal(std::string t): type_(t){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other): type_(other.type_) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const{
	return type_;
}

