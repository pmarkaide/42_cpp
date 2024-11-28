/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/28 14:57:47 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void Phonebook::displayMenu() const {
    std::cout << "Welcome to the Phonebook Application!" << std::endl;
    std::cout << "1. Add a contact" << std::endl;
    std::cout << "2. View all contacts" << std::endl;
    std::cout << "3. Find a contact by name" << std::endl;
    std::cout << "4. Exit" << std::endl;
}
