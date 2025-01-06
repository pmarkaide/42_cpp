/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:56:09 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

// Constructors and Destructors
FragTrap::FragTrap(const std::string& name):
	ClapTrap(name){
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_= 30;

	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src){
	if (this != &src) {
		ClapTrap::operator=(src);
	}
	std::cout << "FragTrap Copy Assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << name_ << " highFive everyone!" << std::endl;
}