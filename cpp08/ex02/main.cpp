/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:12:36 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/30 11:13:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>


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
    std::cout << "\nStandard stack size: " << s.size() << std::endl;
    

	MutantStack<int> m2stack;
	m2stack.push(5);
	m2stack.push(17);
	std::cout << m2stack.top() << std::endl;
	m2stack.pop();
	std::cout << "Stack size: "<< m2stack.size() << std::endl;
	m2stack.push(3);
	m2stack.push(5);
	m2stack.push(737);
	m2stack.push(0);
	MutantStack<int>::iterator it2 = m2stack.begin();
	MutantStack<int>::iterator ite2 = m2stack.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
	std::cout << *it2 << std::endl;
	++it2;
	}

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Stack size: "<< lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it3 = lst.begin();
	std::list<int>::iterator ite3 = lst.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
	std::cout << *it3 << std::endl;
	++it3;
	}

    return 0;
}