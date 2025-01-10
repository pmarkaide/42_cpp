/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:32:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/10 10:12:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ZOMBIE_HPP
 #define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string name_;

	public:
		Zombie();
		~Zombie();
		void announce(void);
		void	setName(const std::string& zombieNamme);
};

#endif  // ZOMBIE_HPP