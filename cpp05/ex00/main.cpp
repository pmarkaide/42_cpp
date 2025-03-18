/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 10:49:04 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(){

	Bureaucrat bert;
	Bureaucrat bob("Bob", 100);
	std::cout << bob.getName()  << " has a grad of: " << bob.getGrade() << std::endl;

	try
	{
		Bureaucrat pablo("Pablo",200);
	}
	catch (std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	
	
	
}