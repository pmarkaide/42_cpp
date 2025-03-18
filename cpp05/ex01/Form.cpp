/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:44 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 14:01:49 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form(const std::string name, int signGrade, int execGrade): name_(name), signGrade_(signGrade), execGrade_(execGrade){
	if(signGrade < 0 || execGrade < 0)
		throw GradeIsNegativeException();
	if(signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if(signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
};

void Form::beSigned(const Bureaucrat &b){
	if(b.getGrade() > getSignGrade())
		throw GradeTooLowException();
	signed_ = true;
}

std::string Form::getName() const{
	return(name_);
}

int Form::getSignGrade() const{
	return(signGrade_);
}

int Form::getExecGrade() const{
	return(execGrade_);
}

bool Form::isSigned() const{
	return(signed_);
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Form Grade is too high! Valid grades are 1-150.";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Form Grade is too low! Valid grades are 1-150.";
}

const char* Form::GradeIsNegativeException::what() const noexcept {	return "Grade must be a positive number.";
	return "Form Grade must be a positive number.";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	std::string sign = "NO";
	if(f.isSigned())
		sign = "YES";
	os << "Form: " << f.getName()
	<< "\nSign Grade: " << f.getSignGrade()
	<< "\nExec Grade: " << f.getExecGrade()
	<<"\nSigned: " << sign;
	return os;
}