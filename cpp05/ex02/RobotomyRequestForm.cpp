/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:44:37 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 11:03:50 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP

#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45),
	target_("Not defined"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45),
	target_(target){
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destroyed..." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	AForm(other),
	target_(other.target_){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
	if(this != &other){
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

double getRandomNumber(){
	
	std::random_device rd; // Create a random device to seed the generator
	std::mt19937 gen(rd()); // Create a Mersenne Twister random number generator
	std::uniform_real_distribution<double> dis(0.0, 1.0); // Create a uniform distribution between 0 and 1
	double random_number = dis(gen); // Generate and print a random number
	return random_number;
}

// actions
void	RobotomyRequestForm::beExecuted(void) const{
	std::cout << "Starting Robotomization...." << std::endl;
	if(getRandomNumber() > 0.5)
		std::cout << target_ << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomization failed on " << target_ << std::endl;
}

	

#endif // ROBOTOMYREQUESTFORM_HPP