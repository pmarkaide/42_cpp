/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:54 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/06 17:11:30 by pmarkaid         ###   ########.fr       */
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

void write_file(const std::string& filename, const std::string& content) {
	std::ofstream file(filename);

	if (!file) {
		throw std::runtime_error("Cannot open file for writing: " + filename);
	}

	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	try {
		file << content;

		if (file.bad()) {
			throw std::runtime_error("Error writing to file");
		}
	}
	catch (const std::exception& e) {
		throw std::runtime_error("File write error: " + std::string(e.what()));
	}
}

void replace(const std::string& infile, const std::string& s1, const std::string& s2)
{
	std::string fileContents;

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
	
	size_t pos = 0;
	std::string modifiedContents;

	while ((pos = fileContents.find(s1, pos)) != std::string::npos) {
		modifiedContents += fileContents.substr(0, pos);
		modifiedContents += s2;
		pos += s1.length();
		fileContents = fileContents.substr(pos);
	}
	modifiedContents += fileContents;
	write_file(infile + ".replace", modifiedContents);
}