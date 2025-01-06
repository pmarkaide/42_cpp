/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:51:20 by pmarkaid         ###   ########.fr       */
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