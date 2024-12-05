/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:51:03 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 13:32:50 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string name_;

	public:
		Zombie(std::string zombieName);
		~Zombie();
		void announce(void);
};

#endif  // ZOMBIE_HPP