/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:52:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:18:28 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

#ifndef DOG_HPP
 #define DOG_HPP

class Dog: public Animal {
	public:
		Dog();
		~Dog() override;
		void makeSound() const override;
};


#endif // DOG_HPP