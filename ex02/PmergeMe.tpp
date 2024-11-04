/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:07:27 by gdaignea          #+#    #+#             */
/*   Updated: 2024/11/04 17:20:35 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

template<typename T>
T	findMaxNumbers(T& arr) {
	T	maxNumbers;
	size_t	size = arr.size();

	for (int i = 0; i < size - 1; i += 2) {
		maxNumbers.push_back(std::max(arr[i], arr[i + 1]));
	}
	if (size % 2 == 0){
		maxNumbers.push_back(arr[size - 1]);
	}
	
	return	maxNumbers;
}

template<typename T>
bool	isSorted(T const& arr) {
	for (typename T::iterator it = arr.begin(); it < arr.end() - 1; ++it) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

template<typename T>
void	sortTwo(T& arr) {
	clock_t start, end;
	start = clock();

	typename T::iterator	first = arr.begin();
	typename T::iterator	last = arr.end();
	--last;
	
	std::swap(*first, *last);

	end = clock();
	std::cout << "After :\t" << *first << " " << *last << std::endl;
	std::cout << "Time to process a range of 2 elements with " << typeid(T).name() << ": " << end - start << std::endl;
	return;
}

template<typename T>
T	mergeSort(const	T& arr) {
	int	size = arr.size();
	if (size <= 1)
		return arr;
	
	int	mid = size / 2;
	T	left(arr.begin(), arr.begin() + mid);
	T	right(arr.begin() + mid, arr.end());

	left = mergeSort(left);
	right = mergeSort(right);

	T	result;
	typename T::iterator	l_it = left.begin();
	typename T::iterator	r_it = right.begin();
	while (l_it != left.end() && r_it != right.end()) {
		if (*l_it < *r_it) {
			result.push_back(*l_it);
			l_it++;
		} else {
			result.push_back(*r_it);
			r_it++;
		}
	}
	while (l_it != left.end()) {
		result.push_back(*l_it);
		l_it++;
	}
	while (r_it != right.end()) {
		result.push_back(*r_it);
		r_it++;
	}

	return result;
}