/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:38:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 13:48:54 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef SCAPTRAP_HPP
 #define SCAPTRAP_HPP

class ScapTrap : public ClapTrap{
	private:
		std::string name_;
		int hitPoints_;
		int energyPoints_;
		int attackDamage_;

	public:
		ScapTrap(const std::string& name);  // Constructor
		ScapTrap(const ScapTrap& src);  // Copy constructor
		ScapTrap &operator=(const ScapTrap& src); // Copy Assignment operator
		~ScapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif // SCAPTRAP_HPP