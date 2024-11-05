/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:07:27 by gdaignea          #+#    #+#             */
/*   Updated: 2024/11/05 16:52:05 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

template<typename T>
T	findMaxNumbers(T& arr) {
	T	maxNumbers;
	typename T::iterator	it = arr.begin();

 	while (it != arr.end()) {
        typename T::iterator next_it = it;
		++next_it; 

		if (next_it != arr.end()) {
			maxNumbers.push_back(std::max(*it, *next_it));
			it = ++next_it;
		} else {
			maxNumbers.push_back(*it);
			++it;
		}
    }

	return	maxNumbers;
}

template<typename T>
bool	isSorted(T const& arr) {
	typename T::const_iterator it = arr.begin();
	typename T::const_iterator next_it = it;
	++next_it;

	while (next_it != arr.end()) {
		if (*it > *next_it)
			return false;
		++it;
		++next_it;
	}
	return true;
}

template<typename T>
void	sortTwo(T& arr) {

	typename T::iterator	first = arr.begin();
	typename T::iterator	last = arr.end();
	--last;
	
	std::swap(*first, *last);
	return;
}

template<typename T>
void	insertInArr(T& arr, int value) {
	typename T::iterator	pos = arr.begin();
	while (pos != arr.end() && *pos < value) {
		++pos;
	}
	arr.insert(pos, value);
}

template<typename T>
T mergeSort(const T& arr) {
	int size = arr.size();
	if (size <= 1)
		return arr;

	int mid = size / 2;

	typename T::const_iterator mid_it = arr.begin();
	std::advance(mid_it, mid);

	T left(arr.begin(), mid_it);
	T right(mid_it, arr.end());

	left = mergeSort(left);
	right = mergeSort(right);

	T result;
	typename T::iterator l_it = left.begin();
	typename T::iterator r_it = right.begin();

	while (l_it != left.end() && r_it != right.end()) {
		if (*l_it < *r_it) {
			result.push_back(*l_it);
			++l_it;
		} 
		else {
			result.push_back(*r_it);
			++r_it;
		}
	}
	while (l_it != left.end()) {
		result.push_back(*l_it);
		++l_it;
	}
	while (r_it != right.end()) {
		result.push_back(*r_it);
		++r_it;
	}

	return result;
}


template<typename T>
T	fordJohnsonSort(T& arr) {

	T	arrMaxs = findMaxNumbers(arr);
	T	arrSubSort = mergeSort(arrMaxs);

	typename T::iterator	it = arr.begin();
	std::advance(it, 2);
	int	firstPairMin = *std::min_element(arr.begin(), it);
	insertInArr(arrSubSort, firstPairMin);

	for (it = arr.begin(); it != arr.end(); ++it) {
		if (std::find(arrSubSort.begin(), arrSubSort.end(), *it) == arrSubSort.end())
			insertInArr(arrSubSort, *it);
	}

	return arrSubSort;
}