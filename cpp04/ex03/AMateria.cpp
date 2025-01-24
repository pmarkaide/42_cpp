/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:31:35 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/24 12:49:28 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria(): type_("Unkown"), owned_(false), inFloor_(false){
	std::cout << "AMateria constructor called. Create: " <<  type_ << std::endl;
};

AMateria::AMateria(std::string const & type): type_(type), owned_(false), inFloor_(false){
	std::cout << "AMateria constructor called. Create: " <<  type_ << std::endl;
};

AMateria::~AMateria(){
	std::cout << "AMateria destructor called. Destroy: " <<  type_ << std::endl;
};

std::string const & AMateria::getType() const{
	return type_;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* throws something at " << target.getName() << " *" << std::endl;
}

void AMateria::setOwned(bool owned){
	owned_ = owned;
}

bool AMateria::getOwned() const{
	return owned_;
}

void AMateria::setFloor(bool inFloor){
	inFloor_ = inFloor;
}

bool AMateria::getFloor() const{
	return inFloor_;
}
