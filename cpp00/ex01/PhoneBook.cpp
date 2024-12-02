/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 17:09:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iomanip>         // setw
# include <stdlib.h>        // clear
#include <thread>           // sleep_for
#include <chrono>           // duration

// STATIC FUNCTIONS

static void displayMenu() {
    std::cout << "Please choose among the options:" << std::endl;
    std::cout << "ADD: Add a Contact" << std::endl;
    std::cout << "SEARCH: Get details of a Contact" << std::endl;
    std::cout << "EXIT: Exit the program\n" << std::endl;
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

static std::string evaluate_input(const std::string& prompt) {
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

static std::string truncateString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

static int getValidNumber() {
    std::string input;

    while (true) {
        std::cin >> input;
        if (input.length() == 1 && input[0] >= '0' && input[0] <= '9') {
            return input[0] - '0';
        } else {
            std::cout << "Invalid input. Please enter a single digit between 0 and 9." << std::endl;
        }
    }
}

static void displayContact(Contact contact){
    std::string input;
    std::cout << "First name: " <<  contact.getFirstName() << std::endl;
    std::cout << "Last name: " <<  contact.getLastName() << std::endl;
    std::cout << "Nick name: " <<  contact.getNickname() << std::endl;
    std::cout << "Phone number: " <<  contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " <<  contact.getDarkestSecret() << std::endl;

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
    displayBanner(false);
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
    std::cout << "\nSelect the contact Index to display: ";
    contact = getValidNumber() -1 ;
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
    std::cout << "System disconnected." << std::endl;
    exit(0);
}

