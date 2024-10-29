/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:12:38 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/29 15:11:44 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <stack>
# include <sstream>
# include <string>

class RPN {

	public:

	std::stack<int>	_stack;

	RPN();
	RPN(RPN const& copy);
	~RPN();

	RPN&	operator=(RPN const& rhs);
	const std::stack<int>&	getStack() const;

};