/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:34:56 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 14:48:38 by pmarkaid         ###   ########.fr       */
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