/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:23 by gdaignea          #+#    #+#             */
/*   Updated: 2024/11/05 17:10:32 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	checkDuplicate(int ac, char** av, int i) {
	for (int j = i + 1; j < ac; ++j) {
		if (av[i] == av[j])
			return false;
	}
	return true;
}

bool	parseNumbers(int ac, char** av) {
	
	if (ac < 3) {
		std::cerr << "Error: program must take at least 2 positives numbers as arguments" << std::endl;
		return false;
	}
	
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (!isdigit(av[i][j])) {
				std::cerr << "Error: program must take positive numbers only" << std::endl;
				return false;
			}
			if (!checkDuplicate(ac, av, i)) {
				std::cerr << "Error: program must not take duplicated numbers" << std::endl;
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

	PmergeMe	FjSort;
	FjSort.runSorting(ac, av);

	return 0;
}