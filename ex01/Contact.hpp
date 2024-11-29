/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 11:28:55 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP


#include <string>

class Contact {
private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;
    std::string darkestSecret_;

public:
    Contact() {};
    ~Contact() {};

    void setFirstName(const std::string& firstName) { firstName_ = firstName; }
    void setLastName(const std::string& lastName) { lastName_ = lastName; }
    void setNickname(const std::string& nickname) { nickname_ = nickname; }
    void setPhoneNumber(const std::string& phoneNumber) { phoneNumber_ = phoneNumber; }
    void setDarkestSecret(const std::string& secret) { darkestSecret_ = secret; }
};

#endif  // CONTACT_HPP