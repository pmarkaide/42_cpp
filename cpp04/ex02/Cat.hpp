/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:30 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 10:40:49 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"
# include "Brain.hpp"

#ifndef CAT_HPP
 #define CAT_HPP

class Cat: public AAnimal {
	private:
		Brain *brain_;

	public:
		Cat();								// Default constructor
		Cat(const Cat& other);				// Copy constructor
		Cat& operator=(const Cat& other);	// Copy assignment operator
		~Cat() override;					// Destructor
	
		void makeSound() const override;
		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
};

#endif // CAT_HPP

