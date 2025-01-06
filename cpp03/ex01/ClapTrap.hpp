/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:22:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 13:08:57 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	private:
		std::string name_;
		int hitPoints_;
		int energyPoints_;
		int attackDamage_;
		
	public:
		ClapTrap(const std::string& name);  // Constructor
		ClapTrap(const ClapTrap& src);  // Copy constructor
		ClapTrap &operator=(const ClapTrap& src); // Copy Assignment operator
		virtual ~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP