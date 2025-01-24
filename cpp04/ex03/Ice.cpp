/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:53:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/24 13:14:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
	std::cout << "Ice constructor called" << std::endl;	
}

Ice::Ice(const Ice& other): AMateria(other.getType()) {
	owned_ = other.owned_;
    inFloor_ = other.inFloor_;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

