/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/13 09:37:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iomanip>         // setw
# include <stdlib.h>        // clear
#include <thread>           // sleep_for
#include <chrono>           // duration

// STATIC FUNCTIONS

static void displayMenu() {
    std::cout << "Please choose among the options:\n" << std::endl;
    std::cout << "  ADD:		Add a Contact" << std::endl;
    std::cout << "  SEARCH:	Get details of a Contact" << std::endl;
    std::cout << "  EXIT:		Exit the program\n" << std::endl;
    std::cout << "Option: ";
}

static void displayBanner(bool menu){
    system("clear");
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
    if(menu)
        displayMenu();
}

static void displayWelcomeMessage() {
    std::cout << "Connecting to the server..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Connection established!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\n====================================" << std::endl;
    std::cout << "   Welcome aboard the PhoneBook!" << std::endl;
    std::cout << "   Your data is safe... probably." << std::endl;
    std::cout << "   Remember: Trust no toaster!" << std::endl;
    std::cout << "   Stay sharp. The Cylons could be" << std::endl;
    std::cout << "   anywhere, even in your contacts." << std::endl;
    std::cout << "====================================\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "\nRedirecting to the console...\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "\nType CONNECT to continue\n";

	std::string input;
    while (true) {
        std::getline(std::cin, input);
        if(input != "CONNECT"){
            std::cout << "\nType CONNECT to continue\n";
            continue;
        }
        if(input == "CONNECT"){
            displayBanner(true);
            break;
        }
    }
}

static std::string evaluate_input(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin.clear();
        if (std::getline(std::cin, input)) {
            if (!input.empty() && input.find_first_not_of(" \t\n\r\f\v") != std::string::npos) {
                return input;
            }
            std::cout << "Input cannot be empty or only whitespace. Please try again\n";
        } else {
            if (std::cin.eof()) {
                std::cin.clear();
                std::cout << "\n\nEOF found! Exiting program..." << std::endl;
                exit(0);
            }
        }
    }
}

static std::string truncateString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

static int getValidIndex(int nbContacts_) {
    std::string input;

    int maxIndex = std::min(nbContacts_, 8);

    while (true) {
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cin.clear();
            std::cout << "\n\nEOF found! Exiting program..." << std::endl;
            exit(0);
        }
        if (input.empty() || input.find_first_not_of(" \t\n\r\f\v") == std::string::npos) {
            std::cout << "Input cannot be empty. Please try again\n";
            std::cout << "Index: ";
            continue;
        }
        if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
            int number = input[0] - '0';
            if (number <= maxIndex) {
                return number;
            }
        }
        std::cout << "\nInvalid input\nPlease enter a single digit between 1 and " << maxIndex << std::endl;
        std::cout << "Index: ";
    }
}

static void displayContact(Contact contact){
    std::cout << "\nFirst name: " <<  contact.getFirstName() << std::endl;
    std::cout << "Last name: " <<  contact.getLastName() << std::endl;
    std::cout << "Nick name: " <<  contact.getNickname() << std::endl;
    std::cout << "Phone number: " <<  contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " <<  contact.getDarkestSecret() << std::endl;

	std::cout << "\nType BACK to continue\n";

	std::string input;
    while (true) {
        std::getline(std::cin, input);
        if(input != "BACK"){
            std::cout << "\nType BACK to continue\n";
            continue;
        }
        if(input == "BACK"){
            displayBanner(true);
            break;
        }
    }
}

// NON STATIC FUNCTIONS

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::choiceAction() {
    std::string action;
    displayBanner(false);
    displayWelcomeMessage();
    displayBanner(true);
    while (true) {
        std::getline(std::cin, action);
        if (std::cin.eof()) {
            std::cin.clear();
            std::cout << "\n\nEOF found! Exiting program" << std::endl;
            exit(0);
        }
        if (action == "EXIT")
            exitProgram();
        else if (action == "ADD")
            addContact();
        else if (action == "SEARCH")
            searchContact();
        else {
            std::cout << "Incorrect choice. Please try again\n" << std::endl;
            std::cout << "Option: ";
        }
    }
}

void  PhoneBook::addContact(){

    Contact newContact;
    displayBanner(false);
    std::cout << "\nAdding a member..." << std::endl;
    std::cout << "Please fill the information:\n" << std::endl;

    newContact.setFirstName(evaluate_input("First name: "));
    newContact.setLastName(evaluate_input("Last name: "));
    newContact.setNickName(evaluate_input("Nick name: "));
    newContact.setPhoneNumber(evaluate_input("Phone number: "));
    newContact.setDarkestSecret(evaluate_input("Darkest Secret: "));
    contacts[nbContacts_ % MAX_CONTACTS] = newContact;
    nbContacts_++;
	std::cout << "\nMember " << newContact.getNickname() << " added succesfully" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\nReturning to the menu..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    displayBanner(true);
}

void  PhoneBook::searchContact(){
    if(nbContacts_ == 0)
    {
        std::cout << "You need to ADD a contact before using SEARCH" << std::endl;
        std::cout << "\nOption: ";
        return;
    }
    displayBanner(false);
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
    int display = std::min(nbContacts_, MAX_CONTACTS);
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
    std::cout << "\nType a Index number to get details of a contact" << std::endl;
    std::cout << "Index: ";
    int contact = getValidIndex(nbContacts_) - 1 ;
    displayContact(contacts[contact]);
}

void PhoneBook::exitProgram() {
    displayBanner(false);
    std::cout << "\n====================================" << std::endl;
    std::cout << " Thank you for using the PhoneBook!" << std::endl;
    std::cout << " Remember: The Cylons might be among" << std::endl;
    std::cout << " us... Stay vigilant, and trust no" << std::endl;
    std::cout << " one with your darkest secret!" << std::endl;
    std::cout << "====================================\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "System disconnected" << std::endl;
    exit(0);
}

