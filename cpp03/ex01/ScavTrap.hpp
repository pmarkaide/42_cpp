/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:38:18 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 09:31:04 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

class ScavTrap : public ClapTrap{
	public:
		ScavTrap(const std::string& name);  // Constructor
		ScavTrap(const ScavTrap& src);  // Copy constructor
		ScavTrap &operator=(const ScavTrap& src); // Copy Assignment operator
		~ScavTrap();

		void attack(const std::string& target) override;
		void guardGate();
};

#endif // SCAvTRAP_HPP