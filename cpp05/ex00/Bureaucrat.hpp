/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:00 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 10:24:35 by pmarkaid         ###   ########.fr       */
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
		//std::string getName();
		//int getGrade();
		// increaseGrade(int amount)
		// decreaseGrade(int amount)
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
};

#endif // BUREAUCRAT_HPP