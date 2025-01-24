/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:31:39 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/24 12:49:16 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type_;
		bool owned_;
		bool inFloor_;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &other) = delete;
		AMateria &operator=(const AMateria &other) = delete;
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		bool getOwned() const;
		void setOwned(bool owned);
		bool getFloor() const;
		void setFloor(bool owned);
		
};

#endif // AMATERIA_HPP
