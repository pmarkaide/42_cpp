/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:22 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/29 13:38:15 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    PhoneBook phonebook;
    
    (void)argv;
    if(argc != 1)
    {
        std::cout << "Usage: ./awesome_phonebook" << std::endl;
        exit(1);
    }
    
    phonebook.choiceAction();
    
    return 0;
}

