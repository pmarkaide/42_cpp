/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 15:48:27 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor and Destructor
Contact::Contact() {}
Contact::~Contact() {}

// Setter Functions
void Contact::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}

void Contact::setNickName(const std::string& nickname) {
    nickName_ = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    phoneNumber_ = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& secret) {
    darkestSecret_ = secret;
}

// Getter Functions
std::string Contact::getFirstName() {
    return firstName_;
}

std::string Contact::getLastName() {
    return lastName_;
}

std::string Contact::getNickname() {
    return nickName_;
}

std::string Contact::getPhoneNumber() {
    return phoneNumber_;
}

std::string Contact::getDarkestSecret() {
    return darkestSecret_;
}
