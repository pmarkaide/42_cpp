/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 20:58:31 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int main(){

	std::cout << "====== Form and Bureaucrat Test ======" << std::endl;
    
    try {
        // Test 1: Create a form with valid grades
        std::cout << "\n--- Test 1: Creating a valid form ---" << std::endl;
        PresidentialPardonForm Pardon("Biden");
		std::cout << Pardon << "\n" <<std::endl;
		Bureaucrat highRanking("Alice", 1);
		std::cout << std::endl;
		highRanking.signForm(Pardon);
		std::cout << std::endl;
		highRanking.executeForm(Pardon);
		std::cout << std::endl;

		std::cout << "\n--- Test 2: Low level Bureocrat messing up---" << std::endl;
		Bureaucrat lowRanking("Bob", 150);
		std::cout << std::endl;
		lowRanking.signForm(Pardon);
		std::cout << std::endl;
		lowRanking.executeForm(Pardon);
		std::cout << std::endl;

		std::cout << "\n--- Test 3: Execute unsigned form ---" << std::endl;
		PresidentialPardonForm Pardon2("Obama");
		std::cout << Pardon2 << "\n" <<std::endl;
		Bureaucrat highRanking2("Alice", 1);
		std::cout << std::endl;
		highRanking2.executeForm(Pardon2);
		std::cout << std::endl;

		std::cout << "\n--- Test 4: Robotomize someone ---" << std::endl;
		RobotomyRequestForm Roboto("Obama");
		std::cout << Roboto << "\n" <<std::endl;
		std::cout << std::endl;
		highRanking.signForm(Roboto);
		std::cout << std::endl;
		highRanking.executeForm(Roboto);
		std::cout << std::endl;

		std::cout << "\n--- Test 5: Plan some shubbery ---" << std::endl;
		ShrubberyCreationForm Shub("Home");
		std::cout << Shub << "\n" <<std::endl;
		std::cout << std::endl;
		highRanking.signForm(Shub);
		std::cout << std::endl;
		highRanking.executeForm(Shub);
		std::cout << std::endl;
		
		std::cout << "\n--- Test 6: Intern creates a valid form ---" << std::endl;
		Intern intern;
		std::cout << std::endl;
		AForm *form = intern.makeForm("PresidentialPardonForm", "Trump");
		if (form) {
		    std::cout << *form << std::endl;
			std::cout << std::endl;
		    delete form;
		}

		std::cout << "\n--- Test 7 Intern handles invalid form request ---" << std::endl;
		try{
			AForm *invalidForm = intern.makeForm("InvalidFormName", "Trump");
			if(!invalidForm)
				std::cout << "Invalid form created" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		
		std::cout << "\n--- Test 8: Bureaucrat orders Intern to create, sign, and execute a PresidentialPardonForm ---" << std::endl;

		Intern intern2;
		Bureaucrat highRankingONE("Trump", 1);
		std::cout << std::endl;

		AForm *form2 = intern.makeForm("PresidentialPardonForm", "Elon Musk");
		std::cout << *form2 << std::endl;
		std::cout << std::endl;

		highRanking.signForm(*form2);
		std::cout << std::endl;

		highRankingONE.executeForm(*form2);
		std::cout << std::endl;
		delete form;

		std::cout << "\n--- Cleanup ---" << std::endl;

    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;

	
	
}