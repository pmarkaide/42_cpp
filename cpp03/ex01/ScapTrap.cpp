/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:39:49 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 13:47:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScapTrap.hpp"

// Constructors and Destructors
ScapTrap::ScapTrap(const std::string& name):
	ClapTrap(name),
	hitPoints_(100),
	energyPoints_(50),
	attackDamage_(20){

	std::cout << "ScapTrap Constructor called" << std::endl;
}

ScapTrap::ScapTrap(const ScapTrap& src): ClapTrap(src) {
	std::cout << "ScapTrap Copy constructor called" << std::endl;
}

ScapTrap & ScapTrap::operator=(ScapTrap const & src){
	if (this != &src) {
		ClapTrap::operator=(src);
	}
	std::cout << "ScapTrap Copy Assignment operator called" << std::endl;
	return *this;
}

ScapTrap::~ScapTrap(){
	std::cout << "ScapTrap  Destructor called" << std::endl;
}
