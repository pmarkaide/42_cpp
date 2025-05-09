/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:22 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/03 16:38:10 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

