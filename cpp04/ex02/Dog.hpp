/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:42 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 10:40:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"
# include "Brain.hpp"

#ifndef DOG_HPP
 #define DOG_HPP

class Dog: public AAnimal {
	private:
		Brain *brain_;

	public:
		Dog();								// Default constructor
		Dog(const Dog& other);				// Copy constructor
		Dog& operator=(const Dog& other);	// Copy assignment operator
		~Dog() override;					// Destructor
	
		void makeSound() const override;
		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
};


#endif // DOG_HPP