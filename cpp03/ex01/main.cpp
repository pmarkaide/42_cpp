/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:09:21 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:03:50 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScapTrap.hpp"

int main(void){
	
	std::cout << std::endl;
	
	ClapTrap a("Carl");
	std::cout << std::endl;
	
	ScapTrap b("Steve");
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	b.attack("Tom");
	std::cout << std::endl;
	
}