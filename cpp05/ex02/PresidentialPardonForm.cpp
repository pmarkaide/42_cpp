/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/08 12:42:08 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5),
	target_("Not defined"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	target_(target){
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destroyed..." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	AForm(other),
	target_(other.target_){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
	if(this != &other){
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

// actions
void	PresidentialPardonForm::beExecuted(void) const{
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
