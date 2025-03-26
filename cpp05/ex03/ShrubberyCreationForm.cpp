/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:46 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 11:24:53 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137),
	target_("Not defined"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	target_(target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destroyed..." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	AForm(other),
	target_(other.target_){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
	if(this != &other){
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

std::string shrubbery = R"(         ,.,
        MMMM_    ,..,
          "_ "__"MMMMM          ,...,,
   ,..., __." --"    ,.,     _-"MMMMMMM
  MMMMMM"___ "_._   MMM"_."" _ """"""
   """""    "" , \_.   "_. ."
          ,., _"__ \__./ ."
         MMMMM_"  "_    ./
          ''''      (    )
   ._______________.-'____"---._
    \                          /
     \________________________/
     (_)                    (_)
)";

// actions
void	ShrubberyCreationForm::beExecuted(void) const{
	std::cout << "Planting shrubbery at " << target_ << " ..."<< std::endl;
	std::ofstream file(target_);
	if (!file) {
		throw std::runtime_error("Cannot open file for writing: " + target_);
	}
	file << shrubbery;
}