/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:35 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 10:29:10 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain_(new Brain()){
	std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(const Dog& other): Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Dog::~Dog() {
	delete brain_;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Dog sound" << std::endl;
};

void Dog::setIdea(int index, const std::string& idea) {
	brain_->setIdea(index, idea);
}

const std::string& Dog::getIdea(int index) const {
	return brain_->getIdea(index);
}
