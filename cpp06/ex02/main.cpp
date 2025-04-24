/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:47:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 12:50:36 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main() {

   // Test with specific types
   std::cout << "\nTesting with known types:" << std::endl;
    
   Base* a = new A();
   std::cout << "Type A - Pointer: ";
   identify(a);
   std::cout << "Type A - Reference: ";
   identify(*a);
   delete a;
   
   Base* b = new B();
   std::cout << "Type B - Pointer: ";
   identify(b);
   std::cout << "Type B - Reference: ";
   identify(*b);
   delete b;
   
   Base* c = new C();
   std::cout << "Type C - Pointer: ";
   identify(c);
   std::cout << "Type C - Reference: ";
   identify(*c);
   delete c;
	
    std::cout << "\n\nCreating 10 random objects and identifying them:" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        // Generate a random object
        Base* obj = generate();
        
        std::cout << "Object " << i + 1 << ": ";
        
        // Identify using pointer
        std::cout << "Pointer identifies as: ";
        identify(obj);
        
        // Identify using reference
        std::cout << "Reference identifies as: ";
        identify(*obj);
        
        std::cout << std::endl;
        
        // Clean up
        delete obj;
    }
    
 
    
    return 0;
}
