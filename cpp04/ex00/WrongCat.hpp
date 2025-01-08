/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:40:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:54:42 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
 #define WRONGCAT_HPP

class WrongCat: public WrongAnimal {
	public:
		WrongCat();								// Default constructor
		WrongCat(const WrongCat& other);				// Copy constructor
		WrongCat& operator=(const WrongCat& other);	// Copy assignment operator
		~WrongCat() override;					// Destructor
	
		void makeSound() const;
};

#endif // WRONGCAT_HPP


