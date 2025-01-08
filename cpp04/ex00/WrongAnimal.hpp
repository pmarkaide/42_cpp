/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:39:57 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:54:15 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
	protected:
		std::string type_;

	public:
		WrongAnimal();
		WrongAnimal(std::string t);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();

		std::string getType() const;
		void makeSound() const;
};

#endif // WRONGANIMAL_HPP