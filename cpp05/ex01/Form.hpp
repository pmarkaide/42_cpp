/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 13:13:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP

# include <iostream>


class Form {
	private:
		const std::string name_ = "A00";
		bool signed_ = false;
		const int signGrade_ = 75;
		const int execGrade_ = 75;
		
	public:
		Form() = default;
		Form(std::string name, int signGrade, int execGrade);
		~Form() = default;
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		
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

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP