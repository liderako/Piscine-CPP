/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:39:08 by asvirido          #+#    #+#             */
/*   Updated: 2018/04/02 20:42:10 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Replace.hpp"

void 	error(std::string s) {
	std::cout << s + '\n';
	std::exit(1);
}

int main(int argc, char **argv) {
	// std::ofstream myFile;

	if (argc != 4)
		error("Usage: ./replace fileName s1 s2");
	Replace replace = Replace(argv[2], argv[3], argv[1]);

	replace.validation();
	std::ifstream myFile(replace.getFileName());
	if (myFile.is_open()) {
		std::string line;
		std::ofstream сreate(replace.getCreateFileName());
		while (std::getline(myFile, line)) {
			size_t i = line.find(replace.getS1()) << '\n';
			// if (i == 18446744073709551615)
			// { 
			// 	continue ;
			// }
			// else {
			// 	std::cout << i;
			// }
		}
		myFile.close();
	}
	else {
		error("Error open file");
	}
}
