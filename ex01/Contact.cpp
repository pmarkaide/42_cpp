/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 16:05:58 by pmarkaid         ###   ########.fr       */
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
const std::string& Contact::getFirstName() const{
    return firstName_;
}

const std::string& Contact::getLastName() const{
    return lastName_;
}

const std::string& Contact::getNickname() const{
    return nickName_;
}

const std::string& Contact::getPhoneNumber() const{
    return phoneNumber_;
}

const std::string& Contact::getDarkestSecret() const{
    return darkestSecret_;
}
