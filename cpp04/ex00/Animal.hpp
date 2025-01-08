/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:06:53 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:38:00 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

# include <iostream>

class Animal{
	protected:
		std::string type_;

	public:
		Animal();
		Animal(std::string t);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif // ANIMAL_HPP