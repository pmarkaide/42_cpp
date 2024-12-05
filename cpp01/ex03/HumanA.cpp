/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:31:03 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 17:51:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {}

void HumanA::attack(){
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}