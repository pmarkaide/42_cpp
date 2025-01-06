/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:50:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:51:58 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef SCAPTRAP_HPP
 #define SCAPTRAP_HPP

class ScapTrap : public ClapTrap{
	public:
		ScapTrap(const std::string& name);  // Constructor
		ScapTrap(const ScapTrap& src);  // Copy constructor
		ScapTrap &operator=(const ScapTrap& src); // Copy Assignment operator
		~ScapTrap();

		void attack(const std::string& target) override;
		void guardGate();
};

#endif // SCAPTRAP_HPP