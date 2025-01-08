/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:23:32 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 11:41:07 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(): type_("Animal"){
	std::cout << "Animal constructor called" << std::endl;	
}

Animal::Animal(std::string type): type_(type){
	std::cout << "Animal constructor called as " << type << std::endl;
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

