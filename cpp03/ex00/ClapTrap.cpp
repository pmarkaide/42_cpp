/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:58 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 11:30:29 by pmarkaid         ###   ########.fr       */
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

