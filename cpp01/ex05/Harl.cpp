/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:06:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/07 17:53:21 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ){
	void (Harl::*func[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	std::map<std::string, int> levelMap = {
			{"debug", 0},
			{"info", 1},
			{"warning", 2},
			{"error", 3}
		};

	std::map<std::string, int>::iterator it = levelMap.find(level);
	if (it != levelMap.end())
		(this->*func[it->second])();
	else
		std::cout << "Invalid level!" << std::endl;
};
