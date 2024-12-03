/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 16:34:15 by pmarkaid         ###   ########.fr       */
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
    int nbContacts_ = 0;
    void addContact();
    void searchContact();
    void exitProgram();

public:
    PhoneBook();
    void choiceAction();
};

#endif