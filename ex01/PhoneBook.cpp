/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 11:33:53 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void PhoneBook::displayMenu() {
    std::string choice;

    std::cout << "Welcome to the Awesome PhoneBook!" << std::endl;
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

std::string evaluate_input(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Input cannot be empty. Please try again.\n";
        } else {
            return input;
        }
    }
}


void  PhoneBook::addContact(){

    Contact newContact;

    std::cout << "\nAdding a member..." << std::endl;
    std::cout << "Please fill the information:\n" << std::endl;

    newContact.setFirstName(evaluate_input("First name: "));
    newContact.setFirstName(evaluate_input("Last name: "));
    newContact.setFirstName(evaluate_input("Nick name: "));
    newContact.setFirstName(evaluate_input("Phone number: "));
    newContact.setFirstName(evaluate_input("Darkest Secret: "));
    contacts[n_contact] = newContact;
    n_contact++;
    std::cout << "\nMember succesfully added" << std::endl;
}

void  PhoneBook::searchContact(){
    std::cout << "Searching contacts..." << std::endl;
}