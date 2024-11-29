/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 14:04:54 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iomanip>         // std::setw
# include <limits>          //

void PhoneBook::displayMenu() {
    std::string choice;

    std::cout << "Please choose among the options:" << std::endl;
    std::cout << "ADD: Add a Contact" << std::endl;
    std::cout << "SEARCH: Get details of a Contact" << std::endl;
    std::cout << "EXIT: Exit the program" << std::endl;
}

void PhoneBook::choiceAction() {
    std::string action;

    std::cout << "Welcome to the Awesome PhoneBook!\n" << std::endl;
    displayMenu();
    while (true) {
        
        std::getline(std::cin, action);
        if (std::cin.eof()) {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        if (action == "EXIT") {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
        else if (action == "ADD") {
            addContact();
            displayMenu();
        }
        else if (action == "SEARCH") {
            searchContact();
            displayMenu();
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
        std::cin.clear(); // Clear any error flags

        // Attempt to read input
        if (std::getline(std::cin, input)) {
            // Successful read
            if (!input.empty()) {
                return input;
            }
            std::cout << "Input cannot be empty. Please try again.\n";
        } else {
            // Handle EOF
            if (std::cin.eof()) {
                // Simply clear the EOF flag and continue
                std::cin.clear();
                continue;
            }
            
            // Other input errors
            std::cout << "Input error occurred. Please try again.\n";
        }
    }
}


void  PhoneBook::addContact(){

    Contact newContact;

    std::cout << "\nAdding a member..." << std::endl;
    std::cout << "Please fill the information:\n" << std::endl;

    newContact.setFirstName(evaluate_input("First name: "));
    newContact.setLastName(evaluate_input("Last name: "));
    newContact.setNickName(evaluate_input("Nick name: "));
    newContact.setPhoneNumber(evaluate_input("Phone number: "));
    newContact.setDarkestSecret(evaluate_input("Darkest Secret: "));
    std::cout << "\nMember " << newContact.getNickname() << " succesfully added" << std::endl;
    //displayContact(newContact);
    contacts[n_contact] = newContact;
    n_contact++;
}

void  PhoneBook::displayContact(Contact contact){
    std::cout << "First name: " <<  contact.getFirstName() << std::endl;
    std::cout << "Last name: " <<  contact.getLastName() << std::endl;
    std::cout << "Nick name: " <<  contact.getNickname() << std::endl;
    std::cout << "Phone number: " <<  contact.getPhoneNumber() << std::endl;    
}

std::string truncateString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void  PhoneBook::searchContact(){
   std::cout << "|"
              << std::setw(10) << "First name"
              << "|"
              << std::setw(10) << "Last name"
              << "|"
              << std::setw(10) << "Nick name"
              << "|"
              << std::setw(10) << "Phone nb"
              << "|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < n_contact; i++) {
        std::cout << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName())
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName())
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname())
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getPhoneNumber())
                  << "|" << std::endl;
    }
}
