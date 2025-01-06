/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:09:21 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 12:14:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main(void){
	
	ClapTrap a("Fred");
	ClapTrap b = a;
	ClapTrap c("Tim");

	c = a;

	std::cout << std::endl;
	a.attack("Tom");
	std::cout << std::endl;
	a.takeDamage(5);
	std::cout << std::endl;
	a.beRepaired(5);
	std::cout << std::endl;
	a.takeDamage(5);
	a.takeDamage(5);
	std::cout << std::endl;
	a.takeDamage(5);
	std::cout << std::endl;
	a.beRepaired(5);
	std::cout << std::endl;

	for (int i = 11; i > 0; i--){
		c.attack("Tom");
	}
	
	
}