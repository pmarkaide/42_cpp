/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:28:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 15:31:27 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): count(0) {
	for (int i = 0; i < 4; i++)
		materia_[i] = nullptr;
}

void MateriaSource::learnMateria(AMateria* newMateria){
	
	if (!newMateria || count >= 4)
		return;
	materia_[count++] = newMateria;
};

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < count; i++) {
		if (materia_[i]->getType() == type)
			return materia_[i]->clone();
	}
	return 0;
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < count; i++)
		delete materia_[i];
}
