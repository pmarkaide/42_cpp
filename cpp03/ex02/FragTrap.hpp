/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:39 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/06 14:55:21 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

class FragTrap : public ClapTrap{
	public:
		FragTrap(const std::string& name);  // Constructor
		FragTrap(const FragTrap& src);  // Copy constructor
		FragTrap &operator=(const FragTrap& src); // Copy Assignment operator
		~FragTrap();

		void FragTrap::highFivesGuys(void);
};

#endif // FRAGTRAP_HPP