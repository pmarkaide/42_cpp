/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:47:10 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 10:26:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

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