/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:28:11 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/20 19:48:02 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    // Check if input file is provided
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        // Initialize Bitcoin Exchange with default database file
        BitcoinExchange exchange;
        
        // Check if database was loaded successfully
        if (exchange.isDatabaseEmpty()) {
            std::cerr << "Error: empty database. Cannot proceed." << std::endl;
            return 1;
        }
        
        // Process the input file
        if (!exchange.processInputFile(argv[1])) {
            // Error message is already printed in processInputFile
            return 1;
        }
    }
    catch (const std::exception& e) {
        // Catch any unexpected exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}