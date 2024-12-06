/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:51:08 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 11:15:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/**
 * Creates a temporary Zombie object on the stack with the given name.
 * Automatically destroyed after this function ends.
 */
void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}
