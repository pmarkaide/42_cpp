/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:58:27 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 11:58:31 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
 #define FIXED_HPP

# include <iostream>

class Fixed  {
	private:
		int fixedPoint_;
		static const int fractionalBits_ = 8;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed& src); // Copy constructor
		~Fixed(); // Destructor
		Fixed &operator=(const Fixed& src); // Copy Assigment Operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif // FIXED_HPP