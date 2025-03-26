/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:49:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 20:54:11 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"


Intern::Intern(){
	std::cout << "New intern hired..." << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern fired..." << std::endl;
}

static AForm	*makeShrubberyForm(const std::string target){
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyForm(const std::string target){
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentForm(const std::string target){
	return (new PresidentialPardonForm(target));
}

const char* Intern::InvalidFormCreationException::what() const noexcept {
	return  "I'm just an Intern, I don't know how to make that form";
}

AForm* Intern::makeForm(std::string form, std::string target){
	AForm	*(*formsFunc[])(std::string target) = {&makePresidentForm, &makeRobotomyForm, &makeShrubberyForm};

	const std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	AForm	*newForm = NULL;
	for (size_t i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			newForm = formsFunc[i](target);
			break ;
		}
	}
	if (!newForm)
		throw InvalidFormCreationException();

	return newForm;
}
