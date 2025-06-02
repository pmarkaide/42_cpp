/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/02 21:51:51 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> generateJacobsthal(size_t n);
    void insertWithBinarySearch(std::vector<int>& arr, int value, size_t limit);
    
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    
    std::vector<int> fordJohnsonSort(std::vector<int> arr);
    void printVector(const std::vector<int>& arr);
};

#endif //PMERGEME_HPP