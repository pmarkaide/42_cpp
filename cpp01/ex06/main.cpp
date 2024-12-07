/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:00:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/07 18:16:52 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(int argc, const char *argv[]) {
	
	if(argc != 2){
		std::cout << "Usage: ./harlFilter [DEBUG | INFO | WARNING | ERROR]" << std::endl;
		return 1;
	}
	Harl harl;
	std::string input(argv[1]);
	harl.complain(input);	
	return 0;
}
