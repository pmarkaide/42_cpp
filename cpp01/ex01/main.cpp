/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:33:05 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 15:15:25 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
#include <thread>           // sleep_for
#include <chrono>           // duration

int main()
{
	std::cout << "\nStarting zombie horde creation...\n\n";
	Zombie* horde = zombieHorde(8, "Zombie");
	std::this_thread::sleep_for(std::chrono::seconds(3));
	delete[] horde;
	return 0;
}
