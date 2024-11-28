/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:22 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/28 15:21:16 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    Phonebook phonebook;
    
    (void)argv;
    if(argc != 1)
    {
        std::cout << "Usage: ./awesome_phonebook" << std::endl;
        exit(1);
    }
    
    phonebook.displayMenu();
    
    return 0;
}

