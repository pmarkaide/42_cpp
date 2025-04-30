/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:12:36 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/30 10:44:27 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>


int main()
{
    // Create a MutantStack of integers
    MutantStack<int> mstack;
    
    // Push some values
    mstack.push(5);
    mstack.push(17);
    
    // Display the top element
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    // Pop the top element
    mstack.pop();
    
    // Display size
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    // Add more elements
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Iterate through the stack using our new iterators
    std::cout << "Stack contents using iterators:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Create a standard stack from our MutantStack (should work due to inheritance)
    std::stack<int> s(mstack);
    std::cout << "Standard stack size: " << s.size() << std::endl;
    
    return 0;
}