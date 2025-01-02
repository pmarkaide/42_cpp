/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:04:32 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 14:37:53 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed  {
	private:
		int fixedPoint_;
		static const int fractionalBits_ = 8;

	public:
		Fixed(); // Default constructor
		Fixed(const int nb); // Int based constructor
		Fixed(const float nb); // Float based construtor
		Fixed(const Fixed& src); // Copy constructor
		~Fixed(); // Destructor
		Fixed &operator=(const Fixed& src); // Copy Assigment Operator
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		friend Fixed operator+(const Fixed &one, const Fixed &two);
		friend Fixed operator-(const Fixed &one, const Fixed &two);
		friend Fixed operator*(const Fixed &one, const Fixed &two);
		friend Fixed operator/(const Fixed &one, const Fixed &two);
};

#endif // FIXED_HPP