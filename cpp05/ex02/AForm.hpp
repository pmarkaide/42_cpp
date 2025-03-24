/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/24 17:57:43 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
 #define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool signed_ = false;
		const int signGrade_;
		const int execGrade_;

	protected:
		virtual void beExecuted(void) const = 0;
		
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
		void execute(const Bureaucrat &bureaucrat) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
	
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP