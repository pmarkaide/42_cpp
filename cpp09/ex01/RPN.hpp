/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:11:41 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/01 19:07:51 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN() = default;
    RPN(const RPN&) = default;
    RPN& operator=(const RPN&) = default;
    ~RPN() = default;
    
    int solve(const std::string& expression);

private:
    bool isOperator(const std::string& token) const;
    int calculate(int a, int b, char op) const;
};

#endif