/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:51:44 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 12:18:56 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

#ifndef CAT_HPP
 #define CAT_HPP

class Cat: public Animal {
	public:
		Cat();
		~Cat() override;
		void makeSound() const override;
};

#endif // CAT_HPP


