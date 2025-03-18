/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:03 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 10:24:25 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name){
	if(grade > 150)
		throw GradeTooLowException();
	if(grade < 1)
		throw GradeTooHighException();
};

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade is too high! Valid grades are 1-150.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade is too low! Valid grades are 1-150.";
}