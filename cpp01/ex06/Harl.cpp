/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:00:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/07 18:27:34 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Harl.hpp"

void Harl::debug( void ){
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ){
	std::map<std::string, int> levelMap = {
			{"[DEBUG]", 0},
			{"[INFO]", 1},
			{"[WARNING]", 2},
			{"[ERROR]", 3}
		};

	std::map<std::string, int>::iterator it = levelMap.find(level);
	int levelCode = -1;
	if (it != levelMap.end())
		levelCode = it->second;

	switch (levelCode) {
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
};

