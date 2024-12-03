/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 15:46:15 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <thread>  // For sleep_for
#include <chrono>  // For duration
#define MAX_CONTACTS 8
class PhoneBook {

private:
    Contact contacts[MAX_CONTACTS];
    int nb_contacts;
    void addContact();
    void searchContact();
    void displayBanner(bool menu);
    void displayMenu();
    void displayContact(Contact);
    void exitProgram();

public:
    PhoneBook() : nb_contacts(0) {};
    void choiceAction();
};

#endif