/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:03 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 14:06:27 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name){
	if(grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
	grade_ = grade;
	std::cout << "New bureaucrat hired..." << std::endl;
};

void Bureaucrat::increaseGrade(int amount){
	if(amount < 0)
		throw GradeIsNegative();
	if(getGrade() - amount < 1)
		throw GradeTooHighException();
	grade_ -= amount;
}

void Bureaucrat::decreaseGrade(int amount){
	if(amount < 0)
		throw GradeIsNegative();
	if(getGrade() + amount >150)
		throw GradeTooHighException();
	grade_ += amount;
}


void Bureaucrat::signForm(Form &f){
	try{
		f.beSigned(*this);
		std::cout << getName() << " signs " << f.getName() << std::endl;
	}
	catch (std::exception & e){
		std::cout << getName() << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::string Bureaucrat::getName() const{
	return(name_);
}

int Bureaucrat::getGrade() const{
	return(grade_);
}

const char* Bureaucrat::GradeIsNegative::what() const noexcept {
	return "Bureaucrat Grade must be a positive number.";
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Bureaucrat Grade is too high! Valid grades are 1-150.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Bureaucrat Grade is too low! Valid grades are 1-150.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}