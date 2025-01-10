/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:33:05 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/10 10:13:12 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	std::cout << "\nStarting zombie horde creation...\n\n";
	Zombie* horde = zombieHorde(8, "Steve");

	delete[] horde;
	return 0;
}
