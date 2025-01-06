/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:52:35 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected:
		std::string name_;
		int hitPoints_;
		int energyPoints_;
		int attackDamage_;
		
	public:
		ClapTrap(const std::string& name);  // Constructor
		ClapTrap(const ClapTrap& src);  // Copy constructor
		ClapTrap &operator=(const ClapTrap& src); // Copy Assignment operator
		virtual ~ClapTrap();
		
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP