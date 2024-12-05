/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:52:05 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 20:54:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
 #define HUMANB_HPP

# include "Weapon.hpp"
class HumanB {
	private:
		std::string name_;
		Weapon* weapon_;
		
	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack(void);
};

#endif // HUMANB_HPP