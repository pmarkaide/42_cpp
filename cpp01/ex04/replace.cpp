/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 12:22:36 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "replace.hpp"
# include <fstream>
# include <iostream>

std::string read_file(std::string infile){
	std::string line;
	std::string fileContents;
	std::ifstream file(infile);
	if (!file.is_open()) {
		std::cerr << "Failed to open the file!" << std::endl;
	}else {
		while (std::getline(file, line)) {
			fileContents += line + "\n";
		}
	}
	file.close();
	return fileContents;
}


void replace(std::string infile, std::string s1, std::string s2){
	// check infile
	// read infile into a string

	// search s1 index
	// substitute by s2
	// write into outfile
	
}