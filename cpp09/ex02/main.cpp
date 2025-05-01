/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/01 14:57:41 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {

    PmergeMe<std::vector<int>> vec_sorter;
    PmergeMe<std::deque<int>> deq_sorter;
    
    // Parse arguments for both
    if (!vec_sorter.parseArguments(argc, argv)) {
        std::cerr << "Error: enter at least 2 non duplicated positive numbers (up to INT_MAX)" << std::endl;
        std::cerr << "Usage: ./PmergeMe 2 13 15 4" << std::endl;
        return 1;
    }
    
    vec_sorter.display("Before: ");
    vec_sorter.display("After:  ");
    
    return 0;
}