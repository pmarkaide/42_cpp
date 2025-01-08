/* ************************************************************************** */
/*		                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:52:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:33:43 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

#ifndef DOG_HPP
 #define DOG_HPP

class Dog: public Animal {
	public:
		Dog();								// Default constructor
		Dog(const Dog& other);				// Copy constructor
		Dog& operator=(const Dog& other);	// Copy assignment operator
		~Dog() override;					// Destructor
	
		void makeSound() const override;
};


#endif // DOG_HPP