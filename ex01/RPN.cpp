/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:11:30 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/29 15:03:18 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const& copy) { *this=copy; }
RPN::~RPN() {}

RPN&	RPN::operator=(RPN const& rhs) {
	if (this != &rhs) {
		_stack = rhs.getStack();
	}
	return *this;
}

 const std::stack<int>&	RPN::getStack() const { return _stack; }


