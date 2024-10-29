/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:20:52 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/29 15:56:11 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	ft_atoi(const std::string& str) {

	std::stringstream ss(str);
	int result;
	
	ss >> result;
	return result;
}

bool	parseString(std::string& str) {

	std::istringstream	iss(str);
	std::string			token;
	int			operators = 0;
	int			numbers = 0;

	while (iss >> token) {
		if (token == "+" || token == "-" || token == "/" || token == "*")
			operators++;
		else if (isdigit(token[0])) {
			if (token.size() != 1) {
				std::cerr << "Error: numbers must be positive and inferior to 10." << std::endl;
				return false;
			}
			numbers++;
		}
		else {
			std::cerr << "Error: token invalid." << std::endl;
			return false;
		}

	}
	if (numbers != operators + 1) {
		std::cerr << "Error: there must be 1 more number than the number of operators" << std::endl;
		return false;
	}
	return true;
}

int	main(int ac, char** av) {

	if (ac != 2) {
		std::cerr << "Error: program must only take one string as an argument" << std::endl;
	}
	
	std::string			str = av[1];
	if (!parseString(str))
		return 1;
	
	RPN					rpn;
	std::istringstream	iss(str);
	std::string			token;

	while (iss >> token) {

		if (token == "+" || token == "-" || token == "/" || token == "*") {
			if (rpn._stack.size() < 2) {
				std::cerr << "Error: there must be at least 2 numbers in stack to make operation" << std::endl;
				return 1;
			}
			int a = rpn.getStack().top();
			rpn._stack.pop();
			int	b = rpn.getStack().top();
			rpn._stack.pop();
			
			if (token == "+") 
				rpn._stack.push(a + b);
			else if (token == "-")
				rpn._stack.push(b - a);
			else if (token == "*")
				rpn._stack.push(a * b);
			else if (token == "/") {
				if (a == 0) {
					std::cerr << "Error: division by 0 is impossible" << std::endl;
					return 1;
				}
				rpn._stack.push(b / a);
			}
		}

		else if (token.size() == 1 && isdigit(token[0])) {
			int nb = ft_atoi(token);
			rpn._stack.push(nb);
		}
	}

	std::cout << rpn._stack.top() << std::endl;

	return 0;
}