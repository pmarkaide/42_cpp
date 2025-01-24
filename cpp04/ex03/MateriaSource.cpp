/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:28:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/24 13:24:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): count(0) {
	for (int i = 0; i < 4; i++)
		materia_[i] = nullptr;
	std::cout << "MateriaSource constructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* newMateria){
	
	if (!newMateria || count >= 4)
	{
		std::cout << "MateriaSource is full or materia is null" << std::endl;
		return;
	}
	materia_[count++] = newMateria;
};

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < count; i++) {
		if (materia_[i]->getType() == type)
			return materia_[i]->clone();
	}
	std::cout << "Materia not learn yet!" << std::endl;
	return 0;
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < count; i++)
		delete materia_[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}
