/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:44 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 12:52:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"


const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high! Valid grades are 1-150.";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low! Valid grades are 1-150.";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName()
	<< "\nSign Grade: " << f.getSignGrade()
	<< "\nExecution Grade: " << f.getExecGrade();
	return os;
}