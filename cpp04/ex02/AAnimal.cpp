/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:10 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 14:31:12 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "AAnimal.hpp"

AAnimal::AAnimal(): type_("AAnimal"){
	std::cout << "AAnimal constructor called" << std::endl;	
}

AAnimal::AAnimal(std::string t): type_(t){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): type_(other.type_) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const{
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const{
	return type_;
}

