/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:34:56 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 15:48:50 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called"	<< std::endl;
	for (int i = 0; i < 100; i++) {
		ideas_[i] = "empty thought";
	}
};

Brain::Brain(const Brain &other){
	std::cout << "Brain copy constructor called"	<< std::endl;
	for (int i = 0; i < 100; i++) {
		ideas_[i] = other.ideas_[i];
	}
};

Brain& Brain::operator=(const Brain& other){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
};

Brain::~Brain(){
	std::cout << "Brain destructor called"	<< std::endl;
};

const std::string& Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return ideas_[index];
	throw std::out_of_range("Brain::getIdea: Index out of range");
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		ideas_[index] = idea;
	else
		throw std::out_of_range("Brain::setIdea: Index out of range");
}
