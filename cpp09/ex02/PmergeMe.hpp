/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/03 20:08:04 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> generateJacobsthal(size_t n);
    
    template<typename Container>
    void insertWithBinarySearch(Container& arr, int value, size_t limit);
    
public:
    PmergeMe() = default;
    ~PmergeMe() = default;
    PmergeMe(const PmergeMe& other) = default;
    PmergeMe& operator=(const PmergeMe& other) = default;
    
    template<typename Container>
    Container fordJohnsonSort(Container arr);
    
    template<typename Container>
    void printContainer(const Container& arr);
};

#endif //PMERGEME_HPP