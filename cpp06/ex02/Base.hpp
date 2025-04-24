/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:31:17 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 12:50:04 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
    virtual ~Base();
};

// Randomly creates an A, B, or C object and returns it as a Base pointer
Base * generate(void);

// Identifies and prints the type of the object pointed to by p
void identify(Base* p);

// Identifies and prints the type of the object referenced by p
void identify(Base& p);

#endif // BASE_HPP