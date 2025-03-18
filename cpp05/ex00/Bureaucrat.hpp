/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:00 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 11:27:27 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	private:
		const std::string name_ = "Bert";
		int grade_ = 150;

	public:
		Bureaucrat() = default;
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat() = default;
		Bureaucrat(const Bureaucrat& other) = delete;
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		std::string getName() const;
		int getGrade() const;
		void increaseGrade(int amount);
		void decreaseGrade(int amount);
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