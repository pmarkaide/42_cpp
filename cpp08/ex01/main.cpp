/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:15:51 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 22:16:15 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
   try {
       Span sp(5);
       
       sp.addNumber(6);
       sp.addNumber(3);
       sp.addNumber(17);
       sp.addNumber(9);
       sp.addNumber(11);
       
       std::cout << "Longest span: " << sp.longestSpan() << std::endl;
       
       sp.addNumber(25);
   }
   catch (const std::exception& e) {
       std::cout << "Exception: " << e.what() << std::endl;
   }
   
   return 0;
}