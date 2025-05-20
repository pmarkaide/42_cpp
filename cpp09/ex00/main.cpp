/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:28:11 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/20 19:29:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Initialize Bitcoin Exchange with default database file
    BitcoinExchange exchange;
    
    if (!exchange.processInputFile(argv[1])) {
        return 1;
    }
    
    return 0;
}