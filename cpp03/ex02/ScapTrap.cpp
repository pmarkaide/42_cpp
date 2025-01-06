/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:51:55 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScapTrap.hpp"

// Constructors and Destructors
ScapTrap::ScapTrap(const std::string& name):
	ClapTrap(name){
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_= 20;

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
	std::cout << "ScapTrap Destructor called" << std::endl;
}

void ScapTrap::attack(const std::string& target){
	if (energyPoints_ <= 0) {
		std::cout << "ScapTrap " << name_ << " has no energy to attack!" << std::endl;
		return;
	}
	if (hitPoints_ <= 0) {
		std::cout << "ScapTrap " << name_ << " is dead, cannot attack!" << std::endl;
		return;
	}
	energyPoints_--;
	std::cout << "ScapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!"  << std::endl;
}

void ScapTrap::guardGate(){
	std::cout << "ScapTrap " << name_ << " entered Guard Keeper Mode" << std::endl;
}