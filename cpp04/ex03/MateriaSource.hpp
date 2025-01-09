/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:28:34 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 15:29:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
	private:
		AMateria* materia_[4];
		int count;

	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria* newMateria) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif // MATERIASOURCE_HPP