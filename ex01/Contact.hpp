/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 16:29:29 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP


#include <string>

class Contact {
private:
    std::string firstName_;
    std::string lastName_;
    std::string nickName_;
    std::string phoneNumber_;
    std::string darkestSecret_;

public:
    Contact();
    ~Contact();

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickName(const std::string& nickname);
    void setPhoneNumber(const std::string& phoneNumber);
    void setDarkestSecret(const std::string& secret);

    const std::string& getFirstName() const;;
    const std::string& getLastName() const;;
    const std::string& getNickname() const;;
    const std::string& getPhoneNumber() const;;
    const std::string& getDarkestSecret() const;;
};


#endif  // CONTACT_HPP