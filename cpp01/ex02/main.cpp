/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:44 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/10 11:31:54 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	// Print the address
	std::cout << "\nString: " << &brain << std::endl;
	std::cout << "Pointer: " << stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl;

	// Print the value
	std::cout << "\nString: " << brain << std::endl; // Direct access
	std::cout << "Pointer: " << *stringPTR << std::endl; // Dereferencing pointer
	std::cout << "Reference: " << stringREF << std::endl; // Using reference

	
	
	return 0;
}
