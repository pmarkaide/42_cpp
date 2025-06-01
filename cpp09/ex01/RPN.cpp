/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:11:39 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/01 19:08:24 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>

int RPN::solve(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) {
                std::cerr << "Error\n";
                return 1;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            
            if (token == "/" && b == 0) {
                std::cerr << "Error\n";
                return 1;
            }
            
            stack.push(calculate(a, b, token[0]));
        } else {
            if (token.length() != 1 || !std::isdigit(token[0])) {
                std::cerr << "Error\n";
                return 1;
            }
            stack.push(token[0] - '0');
        }
    }
    
    if (stack.size() != 1) {
        std::cerr << "Error\n";
        return 1;
    }
    
    std::cout << stack.top() << std::endl;
    return 0;
}

bool RPN::isOperator(const std::string& token) const {
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

int RPN::calculate(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}