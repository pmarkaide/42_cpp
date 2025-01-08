/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:09:21 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 09:26:41 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

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
	
}