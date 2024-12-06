/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 16:50:37 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <fstream>
#include <iostream>

std::string read_file(const std::string& filename) {
	std::ifstream file(filename);

	if (!file) {
		throw std::runtime_error("Cannot open file: " + filename);
	}

	std::string contents, line;
	file.exceptions(std::ifstream::badbit);
	try {
		while (std::getline(file, line)) {
			contents += line + '\n';
		}
		if (file.bad()) {
			throw std::runtime_error("Error reading file");
		}
	}
	catch (const std::exception& e) {
		throw std::runtime_error("File read error: " + std::string(e.what()));
	}

	return contents;
}

void replace(const std::string& infile, const std::string& s1, const std::string& s2)
{
	std::string fileContents;
	(void)s1;
	(void)s2;
	try {
		fileContents = read_file(infile);

		if (fileContents.empty()) {
			std::cerr << "The file is empty!" << std::endl;
			return;
		}
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return; 
	}
	// search s1 index
	std::cout << fileContents << std::endl;
	// replace s1 by s2
	// write into outfile
}