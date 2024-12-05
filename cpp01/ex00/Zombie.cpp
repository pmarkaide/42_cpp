/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:51:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 13:42:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include <iostream>

// Constructor with initializer list
Zombie::Zombie(std::string zombieName) : name_(zombieName) {}

// Destructor
Zombie::~Zombie(){
	std::cout << "Zombie " << name_ << " has been destroyed.\n";
}

// Announce the zombie presence with a message
void Zombie::announce( void ){
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
