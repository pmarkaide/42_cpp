/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 15:17:16 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {

private:
        Contact contacts[8];
        int n_contact;
        void addContact();
        void searchContact();

public:
    PhoneBook() : n_contact(0) {};
    void displayBanner();
    void displayMenu();
    void choiceAction();
    void displayContact(Contact);
};

#endif