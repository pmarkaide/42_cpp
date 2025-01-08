/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:30 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 14:31:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

#ifndef CAT_HPP
 #define CAT_HPP

class Cat: public Animal {
	public:
		Cat();								// Default constructor
		Cat(const Cat& other);				// Copy constructor
		Cat& operator=(const Cat& other);	// Copy assignment operator
		~Cat() override;					// Destructor
	
		void makeSound() const override;
};

#endif // CAT_HPP

