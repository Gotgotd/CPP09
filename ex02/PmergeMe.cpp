/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:55 by gdaignea          #+#    #+#             */
/*   Updated: 2024/11/04 17:54:41 by gdaignea         ###   ########.fr       */
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
void	PmergeMe::fordJohnsonSort() {
	
	if(isSorted(_list) && isSorted(_vector)) {
		std::cout << "numbers are already sorted" << std::endl;
		return;
	}

	std::cout << "Before:\t";
	for (int i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
	
	if (_list.size() == 2 && _vector.size() == 2) {
		sortTwo(_list);
		sortTwo(_vector);
		return;
	}

	int start, end;
	start = clock();
	std::list<int>	listMaxs = findMaxNumbers(_list);
	std::list<int>	listSubSort = mergeSort(listMaxs);

	std::list<int>::iterator	it = _list.begin();
	std::advance(it, 2);
	int	firstPairMin = *std::min_element(_list.begin(), it);	
	
	std::vector<int>	vectorMaxs = findMaxNumbers(_vector);

}