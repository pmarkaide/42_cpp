/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/28 16:33:57 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void Phonebook::displayMenu() {
    std::string choice;

    std::cout << "Welcome to the Awesome Phonebook!" << std::endl;
    std::cout << "Please choose among the options:" << std::endl;
    std::cout << "ADD: Add a Contact" << std::endl;
    std::cout << "SEARCH: Get details of a Contact" << std::endl;
    std::cout << "EXIT: Exit the program" << std::endl;


    while (true) {
        std::getline(std::cin, choice);
        if (choice == "EXIT") {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
        else if (choice == "ADD") {
            addContact();
            break;
        }
        else if (choice == "SEARCH") {
            searchContact();
            break;
        }
        else {
            std::cout << "Incorrect choice. Please try again\n" << std::endl;
        }
    }
}

void  Phonebook::addContact(){
    std::cout << "Adding a member" << std::endl;
    std::cout << "Please fill the information:" << std::endl;
    this->n_contact++;
    std::cout << "First name:" << std::endl;
    std::cout << "Last name:" << std::endl;
    std::cout << "Nick name:" << std::endl;
    std::cout << "Phone number:" << std::endl;
    std::cout << "Darkest Secret:" << std::endl;
}

void  Phonebook::searchContact(){
    std::cout << "Searching contacts..." << std::endl;
}