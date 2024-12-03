/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 17:08:16 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>         // cout

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
    ~PhoneBook();
    void choiceAction();
};

#endif