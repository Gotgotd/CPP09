/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:42 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/31 15:32:21 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <list>
# include <vector>

class PmergeMe {

	private:

	std::list<int>		_list;
	std::vector<int>	_vector;

	public:

	PmergeMe();
	PmergeMe(PmergeMe const& copy);
	~PmergeMe();

	PmergeMe&				operator=(PmergeMe const& rhs);
	std::list<int> const&	getList() const;
	std::vector<int> const&	getVector() const;

	void	extractNumbers(int ac, char **av);
};