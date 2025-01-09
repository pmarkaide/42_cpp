/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:52:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 20:15:54 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
class Character: public ICharacter
{
	private:
		std::string name_;
		AMateria *materia_[4];
		int count_;

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();
		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter &target) override;
};

#endif // CHARACTER_HPP