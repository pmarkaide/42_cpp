/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:03 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 10:49:35 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name){
	if(grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
	grade_ = grade;
};

void Bureaucrat::increaseGrade(int amount){
	if(getGrade() - amount < 1)
		throw GradeTooHighException();
	grade_ -= amount;
}

void Bureaucrat::decreaseGrade(int amount){
	if(getGrade() + amount >150)
		throw GradeTooHighException();
	grade_ += amount;
}


std::string Bureaucrat::getName(){
	return(name_);
}

int Bureaucrat::getGrade(){
	return(grade_);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high! Valid grades are 1-150.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low! Valid grades are 1-150.";
}