/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 11:58:50 by pmarkaid         ###   ########.fr       */
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
        }
        else if (choice == "SEARCH") {
            searchContact();
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
    newContact.setLastName(evaluate_input("Last name: "));
    newContact.setNickName(evaluate_input("Nick name: "));
    newContact.setPhoneNumber(evaluate_input("Phone number: "));
    newContact.setDarkestSecret(evaluate_input("Darkest Secret: "));
    std::cout << "\nMember " << newContact.getNickname() << " succesfully added" << std::endl;
    displayContact(newContact);
    contacts[n_contact] = newContact;
    n_contact++;
}

void  PhoneBook::displayContact(Contact contact){
    std::cout << "First name: " <<  contact.getFirstName() << std::endl;
    std::cout << "Last name: " <<  contact.getLastName() << std::endl;
    std::cout << "Nick name: " <<  contact.getNickname() << std::endl;
    std::cout << "Phone number: " <<  contact.getPhoneNumber() << std::endl;    
}

void  PhoneBook::searchContact(){
    std::cout << "Searching contact" << std::endl;
    
}