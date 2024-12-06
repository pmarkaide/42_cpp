/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:51:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 11:15:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include <iostream>

/**
 * Constructor for the Zombie class.
 * Initializes a Zombie object with the given name.
 * Prints a message indicating the Zombie has been created.
 */
Zombie::Zombie(std::string zombieName) : name_(zombieName) {
	std::cout << "Zombie " << name_ << " created.\n";
}

/**
 * Destructor for the Zombie class.
 * Cleans up the Zombie object and prints a message indicating destruction.
 */
Zombie::~Zombie(){
	std::cout << "Zombie " << name_ << " has been destroyed.\n";
}

/**
 * Announces the presence of the Zombie with a predefined message.
 */
void Zombie::announce( void ){
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
