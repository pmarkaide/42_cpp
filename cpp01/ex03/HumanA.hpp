/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:48:36 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 16:53:38 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"
# include <string>

class HumanA {
	private:
		Weapon weapon_;
		std::string name_;
		
	public:
		HumanA(std::string type);
		void attack(void);
};