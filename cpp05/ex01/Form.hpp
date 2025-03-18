/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:41:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/18 12:53:38 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP

# include <iostream>


class Form {
	private:
		const std::string name_;
		bool isSigned_ = false;
		const int signGrade_;
		const int executeGrade_;
		
	public:
		Form() = default;
		~Form() = default;
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		
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