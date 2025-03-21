/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/21 15:55:00 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
 #define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name_ = "A00";
		bool signed_ = false;
		const int signGrade_ = 75;
		const int execGrade_ = 75;
		
	public:
		// OCF
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		// getters
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;

		// actions
		void beSigned(const Bureaucrat &b);
		virtual void execute(const std::string &target) = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class GradeIsNegativeException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
	
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // AFORM_HPP