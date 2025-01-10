/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:34:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/10 10:12:03 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
		horde[i].announce();
	}

	return horde;
}
