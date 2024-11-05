/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:55 by gdaignea          #+#    #+#             */
/*   Updated: 2024/11/05 17:01:27 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"
# include "PmergeMe.tpp"

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

int	ft_atoi(const std::string& str) {

	std::stringstream ss(str);
	int result;
	
	ss >> result;
	return result;
}

void	PmergeMe::extractNumbers(int ac, char** av) {
	
	for (int i = 1; i < ac; ++i) {
		std::string	str = av[i];
		int nb = ft_atoi(str);
		_list.push_back(nb);
		_vector.push_back(nb);
	}
}

/*Ford-Johnson algorithm
1. Pair and Compare: Divide the list into pairs and order each pair.
2. Sort Larger Elements: Sort the larger elements (second of each pair) using merge sort
3. Insert Smaller Elements: Insert the smaller elements of the first 2 numbers into the sorted list of larger elements.
4. Handle Unpaired Elements: If there’s an unpaired element, insert it into the correct position.
*/
void	PmergeMe::runSorting(int ac, char** av) {
	
	extractNumbers(ac, av);

	if(isSorted(_list) && isSorted(_vector)) {
		std::cout << "numbers are already sorted" << std::endl;
		return;
	}

	std::cout << "Before:\t";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
	
	if (_list.size() == 2 && _vector.size() == 2) {
		clock_t l_start, l_end;
		l_start = clock();
		sortTwo(_list);
		l_end = clock();

		clock_t v_start, v_end;
		v_start = clock();
		sortTwo(_vector);
		v_end = clock();
		
		std::cout << "After :\t" << _vector[0] << " " << _vector[1] << std::endl;
		std::cout << "Time to process a range of 2 elements with std::list: " << static_cast<double>(l_end - l_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
		std::cout << "Time to process a range of 2 elements with std::vector: " << static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000 << "ms"<< std::endl;
		return;
	}

	clock_t l_start, l_end;
	l_start = clock();
	_list = fordJohnsonSort(_list);
	l_end = clock();

	clock_t v_start, v_end;
	v_start = clock();
	_vector = fordJohnsonSort(_vector);
	v_end = clock();

	std::cout << "After :\t";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " <<  _list.size() << " elements with std::list: " << static_cast<double>(l_end - l_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
	std::cout << "Time to process a range of " <<  _vector.size() << " elements with std::vector: " << static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
}