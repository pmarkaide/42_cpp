/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:17:38 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 20:51:01 by pmarkaid         ###   ########.fr       */
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
		


		std::cout << "\n--- Cleanup ---" << std::endl;

		
        
        
        // // Test 2: Create bureaucrats with different grades
        // std::cout << "\n--- Test 2: Creating bureaucrats ---" << std::endl;
        // Bureaucrat highRanking("Alice", 10);  // High ranking bureaucrat
        // Bureaucrat lowRanking("Bob", 120);    // Low ranking bureaucrat
        
        // std::cout << highRanking << std::endl;
        // std::cout << lowRanking << std::endl;
        
        // // Test 3: High ranking bureaucrat tries to sign the form
        // std::cout << "\n--- Test 3: High ranking bureaucrat signs form ---" << std::endl;
        // highRanking.signForm(taxForm);
        // std::cout << taxForm << std::endl;
        
        // // Test 4: Try to sign again (already signed)
        // std::cout << "\n--- Test 4: Trying to sign an already signed form ---" << std::endl;
        // highRanking.signForm(taxForm);
        
        // // Test 5: Create a new form for the low ranking bureaucrat
        // std::cout << "\n--- Test 5: Low ranking bureaucrat tries to sign high-grade form ---" << std::endl;
        // Form secretForm("Secret Form", 50, 25);
        // lowRanking.signForm(secretForm);
        // std::cout << secretForm << std::endl;
        
        // // Test 6: Low ranking bureaucrat signs a suitable form
        // std::cout << "\n--- Test 6: Low ranking bureaucrat signs suitable form ---" << std::endl;
        // Form simpleForm("Simple Form", 140, 140);
        // lowRanking.signForm(simpleForm);
        // std::cout << simpleForm << std::endl;
        
        // // Test 7: Create invalid forms (should throw exceptions)
        // std::cout << "\n--- Test 7: Creating invalid forms ---" << std::endl;
        // std::cout << "Attempting to create form with grade 0:" << std::endl;
        // try {
        //     Form invalidForm1("Invalid Form", 0, 50);
        // } catch (std::exception &e) {
        //     std::cout << "Exception caught: " << e.what() << std::endl;
        // }
        
        // std::cout << "Attempting to create form with grade 151:" << std::endl;
        // try {
        //     Form invalidForm2("Invalid Form", 100, 151);
        // } catch (std::exception &e) {
        //     std::cout << "Exception caught: " << e.what() << std::endl;
        // }
		
		// // Test 8: Promote Bureaucrat
		// std::cout << "\n--- Test 8: Promote bob for secretForm ---" << std::endl;
		// lowRanking.increaseGrade(100);
		// std::cout << lowRanking << std::endl;
		// lowRanking.signForm(secretForm);
		// std::cout << std::endl;
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;

	
	
}