/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:58:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 17:30:36 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

// constructor with ini
Weapon::Weapon(const std::string& type) : type_(type) {}

// getter
const std::string& Weapon::getType() const{
	return type_;
}

// setter
void Weapon::setType(const std::string& newType){
	type_ = newType;
}
