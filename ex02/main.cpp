/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:23 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/31 15:45:42 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	ft_atoi(const std::string& str) {

	std::stringstream ss(str);
	int result;
	
	ss >> result;
	return result;
}

bool	parseNumbers(int ac, char** av) {
	
	if (ac < 3) {
		std::cerr << "Error: program must take at least 2 positives numbers as arguments" << std::endl;
		return 1;
	}
	
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (!isdigit(av[i][j])) {
				std::cerr << "Error: program must take positive numbers only" << std::endl;
				return false;
			}
		}
		std::string str = av[i];
		int	nb = ft_atoi(str);
		if (nb < 0) {
			std::cerr << "Error: program must take positive numbers only" << std::endl;
			return false;
		}
	}
	return true;
}

int	main(int ac, char** av) {
	
	if (!parseNumbers(ac, av))
		return 1;

	std::cout << "Before:";
	for (int i = 1; i < ac; ++i) {
		std::cout << " " << av[i];
	}
	std::cout << std::endl;

	PmergeMe	FjSort;

	FjSort.extractNumbers(ac, av);

	return 0;
}