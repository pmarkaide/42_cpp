/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:48:36 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 21:20:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
 #define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string name_;
		Weapon& weapon_;
		
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void);
};

#endif // HUMANA_HPP