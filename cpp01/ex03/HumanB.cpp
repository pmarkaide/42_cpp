/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:53:48 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 21:10:41 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"
# include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {}

void HumanB::setWeapon(Weapon& weapon){
	weapon_ = &weapon;
}

void HumanB::attack() {
	if (weapon_) {
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
	} else {
		std::cout << name_ << " has no weapon to attack with!" << std::endl;
	}
}

