/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:44 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/24 17:39:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(): name_("Blank Form"), signGrade_(150), execGrade_(150){
	std::cout << "New form created..." << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade): name_(name), signGrade_(signGrade), execGrade_(execGrade){
	if(signGrade < 0 || execGrade < 0)
		throw GradeIsNegativeException();
	if(signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if(signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	std::cout << "New form created..." << std::endl;
};

void AForm::beSigned(const Bureaucrat &b){
	if(signed_)
		throw FormAlreadySignedException();
	if(b.getGrade() > getSignGrade())
		throw GradeTooLowException();
	signed_ = true;
	std::cout << "Form " << getName() << " is signed by " << b.getName() << std::endl;
}

AForm::AForm(const AForm& other) : name_(other.name_), signed_(other.signed_), signGrade_(other.signGrade_), execGrade_(other.execGrade_) {
	std::cout << "Copy constructor called for " << name_ << std::endl;
}

AForm &AForm::operator=(const AForm& other){
	if(this != &other)
		this->signed_ = other.isSigned();
	return (*this);
}

AForm::~AForm(){
	std::cout << "Form destroyed..." << std::endl;
}

std::string AForm::getName() const{
	return(name_);
}

int AForm::getSignGrade() const{
	return(signGrade_);
}

int AForm::getExecGrade() const{
	return(execGrade_);
}

bool AForm::isSigned() const{
	return(signed_);
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Form Grade is too high! Valid grades are 1-150.";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Form Grade is too low! Valid grades are 1-150.";
}

const char* AForm::GradeIsNegativeException::what() const noexcept {
	return "Form Grade must be a positive number.";
}

const char* AForm::FormAlreadySignedException::what() const noexcept {
	return "Form cannot be signed twice.";
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return "Form cannot be executed without a valid signature.";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form: " << f.getName()
	<< "\nSign Grade: " << f.getSignGrade()
	<< "\nExec Grade: " << f.getExecGrade()
	<<"\nSigned: " << (f.isSigned() ? "YES" : "NO");
	return os;
}

void AForm::execute(const Bureaucrat &bureaucrat) const{
	if(!isSigned())
		throw FormNotSignedException();
	if(bureaucrat.getGrade() > getExecGrade())
		throw GradeTooLowException();
	beExecuted();
}