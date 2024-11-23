/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:44:08 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 20:58:17 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void replaceStringInFile(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	std::ofstream outputFile(filename + ".replace");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
		inputFile.close();
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: The string to be replaced cannot be empty." << std::endl;
		return 1;
	}

	replaceStringInFile(filename, s1, s2);

	return 0;
}