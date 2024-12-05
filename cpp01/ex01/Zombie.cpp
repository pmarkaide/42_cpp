/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:32:59 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 15:12:56 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include <iostream>

// Default constructor
Zombie::Zombie() {};

// Destructor
Zombie::~Zombie(){
	std::cout << "Zombie " << name_ << " has been destroyed.\n";
}

// Announce the zombie presence with a message
void Zombie::announce( void ){
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& zombieName){
	name_ = zombieName;
}
