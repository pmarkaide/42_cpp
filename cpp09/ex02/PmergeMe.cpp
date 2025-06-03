/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/03 20:12:43 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

std::vector<int> PmergeMe::generateJacobsthal(size_t n) {
    if (n == 0) return std::vector<int>();
    if (n == 1) return std::vector<int>(1, 1);
    
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < static_cast<int>(n)) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

template<typename Container>
void PmergeMe::insertWithBinarySearch(Container& arr, int value, size_t limit) {
    size_t left = 0;
    size_t right = std::min(limit, arr.size());
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    arr.insert(arr.begin() + left, value);
}

template<typename Container>
Container PmergeMe::fordJohnsonSort(Container arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    
    if (arr.size() == 2) {
        if (arr[0] > arr[1]) {
            std::swap(arr[0], arr[1]);
        }
        return arr;
    }
    
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = arr.size() % 2;
    int oddElement = hasOdd ? arr.back() : -1;
    
    for (size_t i = 0; i < arr.size() - hasOdd; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }
    
    Container main;
    for (size_t i = 0; i < pairs.size(); i++) {
        main.push_back(pairs[i].first);
    }
    
    main = fordJohnsonSort(main);
    
    std::vector<int> pend;
    for (size_t i = 0; i < main.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == main[i]) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    
    Container result = main;
    
    if (!pend.empty()) {
        insertWithBinarySearch(result, pend[0], result.size());
        
        if (pend.size() > 1) {
            std::vector<int> jacobsthal = generateJacobsthal(pend.size());
            std::vector<bool> inserted(pend.size(), false);
            inserted[0] = true;
            
            for (size_t i = 1; i < jacobsthal.size() && jacobsthal[i] <= static_cast<int>(pend.size()); i++) {
                int groupEnd = jacobsthal[i] - 1;
                int groupStart = (i > 1) ? jacobsthal[i - 1] : 1;
                
                for (int j = groupEnd; j >= groupStart && j >= 1; j--) {
                    if (j < static_cast<int>(pend.size()) && !inserted[j]) {
                        insertWithBinarySearch(result, pend[j], result.size());
                        inserted[j] = true;
                    }
                }
            }
            
            for (size_t i = 1; i < pend.size(); i++) {
                if (!inserted[i]) {
                    insertWithBinarySearch(result, pend[i], result.size());
                }
            }
        }
    }
    
    if (hasOdd && oddElement != -1) {
        insertWithBinarySearch(result, oddElement, result.size());
    }
    
    return result;
}

template<typename Container>
void PmergeMe::printContainer(const Container& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

template std::vector<int> PmergeMe::fordJohnsonSort<std::vector<int>>(std::vector<int> arr);
template std::deque<int> PmergeMe::fordJohnsonSort<std::deque<int>>(std::deque<int> arr);
template void PmergeMe::printContainer<std::vector<int>>(const std::vector<int>& arr);
template void PmergeMe::printContainer<std::deque<int>>(const std::deque<int>& arr);
template void PmergeMe::insertWithBinarySearch<std::vector<int>>(std::vector<int>& arr, int value, size_t limit);
template void PmergeMe::insertWithBinarySearch<std::deque<int>>(std::deque<int>& arr, int value, size_t limit);