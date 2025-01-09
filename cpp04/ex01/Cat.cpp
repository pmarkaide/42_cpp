/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 09:03:15 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain_(new Brain()){
	std::cout << "Cat constructor called" << std::endl;
};

Cat::Cat(const Cat& other): Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
		brain_ = other.brain_;
	}
	return *this;
}

Cat::~Cat() {
	delete brain_;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Cat sound" << std::endl;
};

void Cat::setIdea(int index, const std::string& idea) {
	brain_->setIdea(index, idea);
}

const std::string& Cat::getIdea(int index) const {
	return brain_->getIdea(index);
}



