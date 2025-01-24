/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:30:58 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/24 13:21:37 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
		std::cout << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;
		
		ICharacter* me = new Character("me");
		std::cout << std::endl;
		
		AMateria* m1;
		AMateria* m2;
		m1 = src->createMateria("ice");
		me->equip(m1);
		std::cout << std::endl;
		
		m2 = src->createMateria("cure");
		me->equip(m2);
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");
		std::cout << std::endl;
		
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;
		
		bob->equip(m2);
		std::cout << std::endl;
		
		AMateria* m3;
		m3 = src->createMateria("ice");
		me->equip(m3);
		std::cout << std::endl;
		
		me->unequip(2);
		std::cout << std::endl;

		AMateria* m4;
		m4 = src->createMateria("fire");
		std::cout << std::endl;
		
		delete bob;
		delete me;
		delete src;
		return 0;
}