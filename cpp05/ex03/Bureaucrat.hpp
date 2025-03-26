/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:00 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/24 17:49:30 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string name_ = "Bert";
		int grade_ = 150;

	public:
		// OCF
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		// getters
		std::string getName() const;
		int getGrade() const;

		// setters
		void increaseGrade(int amount);
		void decreaseGrade(int amount);

		// actions
		void signForm(AForm &f);
		void executeForm(AForm const &f);

		// exceptions
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
		class GradeIsNegative : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP