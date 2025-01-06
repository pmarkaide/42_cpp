/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:58 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 12:13:21 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

// Constructors and Destructors
ClapTrap::ClapTrap(const std::string& name) :
	name_(name),
	hitPoints_(10),
	energyPoints_(10),
	attackDamage_(0)
	{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src):
	name_(src.name_),
	hitPoints_(src.hitPoints_),
	energyPoints_(src.energyPoints_),
	attackDamage_(src.attackDamage_)
	{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src){
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &src) {
		name_ = src.name_;
		hitPoints_ = src.hitPoints_;
		energyPoints_ = src.energyPoints_;
		attackDamage_ = src.attackDamage_;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

// Functions

void ClapTrap::attack(const std::string& target){
	if (energyPoints_ <= 0) {
		std::cout << "ClapTrap " << name_ << " has no energy to attack!" << std::endl;
		return;
	}
	if (hitPoints_ <= 0) {
		std::cout << "ClapTrap " << name_ << " is dead, cannot attack!" << std::endl;
		return;
	}
	energyPoints_--;
	std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!"  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hitPoints_ <= 0) {
		std::cout << "ClapTrap " << name_ << " is already dead, he cannot take more hitPoints!" << std::endl;
		return;
	}
	hitPoints_ -= amount;
	std::cout << "ClapTrap " << name_ << " has taken " << amount << " hitPoints of damage";
	if (hitPoints_ <= 0) {
		std::cout << " and now is DEAD!";
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints_ <= 0) {
		std::cout << "ClapTrap " << name_ << " has no energy to repair himself!" << std::endl;
		return;
	}
	if (hitPoints_ <= 0) {
		std::cout << "ClapTrap " << name_ << " is dead, he cannot repair himself!" << std::endl;
		return;
	}
	hitPoints_ += amount;
	std::cout << "ClapTrap " << name_ << " repair himself by " << amount << " points of hitPoints!"  << std::endl;
}

