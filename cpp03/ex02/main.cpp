/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 09:33:09 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void){
	
	std::cout << std::endl;
	
	ClapTrap a("Carl");
	std::cout << std::endl;
	
	ScavTrap b("Steve");
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	b.attack("Tom");
	std::cout << std::endl;
	
	FragTrap c("Fred");
	std::cout << std::endl;
	
	c.highFivesGuys();
	std::cout << std::endl;
	
}