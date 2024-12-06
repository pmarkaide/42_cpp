/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:35:43 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 11:17:12 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Entry point of the program.
 * - Creates a Zombie dynamically and handles memory allocation errors.
 * - Demonstrates temporary stack allocation with `randomChump`.
 * - Ensures cleanup of dynamically allocated memory with `delete`.
 */
int main() {
	Zombie* zombie = newZombie("Steve");
	 if (zombie == nullptr) {
		std::cerr << "Failed to create zombie. Exiting program." << std::endl;
		return 1;
	}
	zombie->announce();
	randomChump("James");
	delete zombie;
}

