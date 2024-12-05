/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:32:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 15:10:39 by pmarkaid         ###   ########.fr       */
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

Zombie* zombieHorde( int N, std::string name );

#endif  // ZOMBIE_HPP