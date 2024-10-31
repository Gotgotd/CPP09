/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:55 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/31 15:44:58 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const& copy) { *this=copy; }
PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(PmergeMe const& rhs) {
	if (this != &rhs) {
		_list = rhs.getList();
		_vector = rhs.getVector();
	}
	return *this;
}

std::list<int> const&	PmergeMe::getList() const { return _list; }
std::vector<int> const&	PmergeMe::getVector() const { return _vector; }

void	PmergeMe::extractNumbers(int ac, char** av) {
	
}