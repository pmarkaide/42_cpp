/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:51:10 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 11:15:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/**
 * Create a new Zombie object in the heap with the given name.
 * Returns nullptr if memory allocation fails.
 */
Zombie* newZombie(std::string name) {
	try {
		Zombie* zombie = new Zombie(name);
		return zombie;
	} catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed for new Zombie: " << e.what() << std::endl;
		return nullptr;
	}
}
