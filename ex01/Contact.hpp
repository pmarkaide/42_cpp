/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 11:56:35 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP


#include <string>

class Contact {
    std::string firstName_;
    std::string lastName_;
    std::string nickName_;
    std::string phoneNumber_;
    std::string darkestSecret_;

public:
    Contact() {};
    ~Contact() {};

    void setFirstName(const std::string& firstName) { firstName_ = firstName; }
    void setLastName(const std::string& lastName) { lastName_ = lastName; }
    void setNickName(const std::string& nickname) { nickName_ = nickname; }
    void setPhoneNumber(const std::string& phoneNumber) { phoneNumber_ = phoneNumber; }
    void setDarkestSecret(const std::string& secret) { darkestSecret_ = secret; }

    std::string getFirstName() { return firstName_; }
    std::string getLastName() { return lastName_; }
    std::string getNickname() { return nickName_; }
    std::string getPhoneNumber() { return  phoneNumber_; }
    std::string getDarkestSecret() { return  darkestSecret_; }
};

#endif  // CONTACT_HPP