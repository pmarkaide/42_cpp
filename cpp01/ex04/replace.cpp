/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 16:07:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <fstream>
#include <iostream>

std::string read_file(const std::string &filename) {
	std::ifstream file(filename);

	file.exceptions(std::ios_base::failbit | std::ios_base::badbit);

	if (!file.is_open()) {
		throw std::ios_base::failure("Failed to open the file!");
	}

	std::string line, fileContents;
	try {
		while (std::getline(file, line)) {
			fileContents += line + "\n";
		}
	} catch (const std::ios_base::failure &e) {
		std::cerr << "File reading error: " << e.what() << std::endl;
		file.close();
		throw;
	}
	file.close();
	return fileContents;
}

void replace(std::string& infile, std::string& s1, std::string& s2)
{
	try {
		std::string fileContents = read_file(infile);

		if (fileContents.empty()) {
			std::cerr << "The file is empty!" << std::endl;
			return;
		}
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return; 
	}
	// search s1 index

	// replace s1 by s2
	// write into outfile
}