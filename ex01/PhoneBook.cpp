/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 12:29:39 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iomanip>         // std::setw
# include <limits>          //
# include <stdlib.h>        // clear

void PhoneBook::displayMenu() {
    std::cout << "Please choose among the options:" << std::endl;
    std::cout << "ADD: Add a Contact" << std::endl;
    std::cout << "SEARCH: Get details of a Contact" << std::endl;
    std::cout << "EXIT: Exit the program" << std::endl;
}

void PhoneBook::displayBanner(){
    //system("clear");
    std::cout << R"(

           █████╗ ██╗    ██╗███████╗███████╗ ██████╗ ███╗   ███╗███████╗          
          ██╔══██╗██║    ██║██╔════╝██╔════╝██╔═══██╗████╗ ████║██╔════╝          
█████╗    ███████║██║ █╗ ██║█████╗  ███████╗██║   ██║██╔████╔██║█████╗      █████╗
╚════╝    ██╔══██║██║███╗██║██╔══╝  ╚════██║██║   ██║██║╚██╔╝██║██╔══╝      ╚════╝
          ██║  ██║╚███╔███╔╝███████╗███████║╚██████╔╝██║ ╚═╝ ██║███████╗          
          ╚═╝  ╚═╝ ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝          
                                                                                  
    ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗ 
    ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝ 
    ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝  
    ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗  
    ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗ 
    ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ 
                                                                                  
    )" << std::endl;
}

void PhoneBook::choiceAction() {
    std::string action;
    system("clear");
    displayBanner();
    displayMenu();
    while (true) {
        std::getline(std::cin, action);
        if (std::cin.eof()) {
            std::cin.clear();
            std::cout << "\n\nEOF found! Exiting program" << std::endl;
            exit(0);
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
        std::cin.clear();
        if (std::getline(std::cin, input)) {
            if (!input.empty()) {
                return input;
            }
            std::cout << "Input cannot be empty. Please try again.\n";
        } else {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cout << "\n\nEOF found! Exiting program" << std::endl;
                exit(0);
            }
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
    contacts[nb_contacts % MAX_CONTACTS] = newContact;
    nb_contacts++;
}

void  PhoneBook::displayContact(Contact contact){
    std::cout << "First name: " <<  contact.getFirstName() << std::endl;
    std::cout << "Last name: " <<  contact.getLastName() << std::endl;
    std::cout << "Nick name: " <<  contact.getNickname() << std::endl;
    std::cout << "Phone number: " <<  contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " <<  contact.getDarkestSecret() << std::endl;
}

std::string truncateString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

int getValidNumber() {
    std::string input;

    while (true) {
        std::cout << "Select the contact Index to display: ";
        std::cin >> input;
        if (input.length() == 1 && input[0] >= '0' && input[0] <= '9') {
            return input[0] - '0';
        } else {
            std::cout << "Invalid input. Please enter a single digit between 0 and 9." << std::endl;
        }
    }
}

void  PhoneBook::searchContact(){
    int contact;
    std::cout << "|"
              << std::setw(10) << "Index"
              << "|"
              << std::setw(10) << "First name"
              << "|"
              << std::setw(10) << "Last name"
              << "|"
              << std::setw(10) << "Nick name"
              << "|"
              << std::setw(10) << "Phone nb"
              << "|" << std::endl;
    std::cout << "|------------------------------------------------------|" << std::endl;
    int display = std::min(nb_contacts, MAX_CONTACTS);
    for (int i = 0; i < display; i++) {
        std::cout << "|"
                  << std::setw(10) << i + 1
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName())
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName())
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname())
                  << "|"
                  << std::setw(10) << truncateString(contacts[i].getPhoneNumber())
                  << "|" << std::endl;
    }
    std::cout << "|------------------------------------------------------|" << std::endl;
    contact = getValidNumber();
    displayContact(contacts[contact]);
}
