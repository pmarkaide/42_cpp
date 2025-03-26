/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:50:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 20:47:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	INTERN_HPP
 #define 	INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		// OCF
		Intern();
		~Intern();
		Intern(const Intern& other) = delete;
		Intern& operator=(const Intern& other) = delete;

		// actions
		AForm* makeForm(std::string form, std::string target);

		class InvalidFormCreationException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};


#endif // 	INTERN_HPP