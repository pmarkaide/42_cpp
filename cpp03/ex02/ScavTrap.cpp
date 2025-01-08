/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 09:30:09 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors and Destructors
ScavTrap::ScavTrap(const std::string& name):
	ClapTrap(name){
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_= 20;

	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src){
	if (this != &src) {
		ClapTrap::operator=(src);
	}
	std::cout << "ScavTrap Copy Assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (energyPoints_ <= 0) {
		std::cout << "ScavTrap " << name_ << " has no energy to attack!" << std::endl;
		return;
	}
	if (hitPoints_ <= 0) {
		std::cout << "ScavTrap " << name_ << " is dead, cannot attack!" << std::endl;
		return;
	}
	energyPoints_--;
	std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!"  << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name_ << " entered Guard Keeper Mode" << std::endl;
}