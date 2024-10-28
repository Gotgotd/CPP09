/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:04:43 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/28 15:07:48 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char** av) {

	(void)ac;
	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::ifstream	file("data.csv");
	if  (!file.is_open()) {
		std::cerr << "Error opening file data.csv" << std::endl;
		return 1;
	}

	Bitcoin	btc;
	btc.extractData(file);
	btc.displayBtcAmount(inputFile);

	file.close();
	inputFile.close();
	return 0;	
}