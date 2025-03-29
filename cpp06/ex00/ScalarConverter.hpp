
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/29 15:49:29 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter{
	private:
		ScalarConverter()=default;
		~ScalarConverter()=default;
		ScalarConverter(const ScalarConverter &other)=delete;
		ScalarConverter &operator=(const ScalarConverter &other)=delete;
	
	public:
		static void convert(const std::string &nput);
};

#endif // SCALARCONVERTER_HPP