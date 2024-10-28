/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:31:34 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/28 17:01:21 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::Bitcoin(Bitcoin const& copy) {
	*this=copy;
}

Bitcoin::~Bitcoin() {}

Bitcoin&	Bitcoin::operator=(Bitcoin const& rhs) {
	if (this != &rhs) {
		_ratesData = rhs._ratesData;
	}
	return *this;
}

std::map<std::string, float>  const&	Bitcoin::getRatesData() const {
	return _ratesData;
}

void	Bitcoin::extractData(std::ifstream& file) {

	std::string line;

	while (std::getline(file, line)) {
		std::istringstream	lineStream(line);
		std::string			date;
		double				rate;
		if (std::getline(lineStream, date, ',') && lineStream >> rate) {
			_ratesData[date] = rate;
		}
	}
}

int	ft_atoi(const std::string& str) {

	std::stringstream ss(str);
	int result;
	
	ss >> result;
	return result;
}

bool	isDateValid(std::string& date) {

	if (date.length() != 11)
		return false;
	if (date[4] != '-' && date[7] != '-')
		return false;

	int	year = ft_atoi(date.substr(0, 4));
	int month = ft_atoi(date.substr(5, 2));
	int	day = ft_atoi(date.substr(8, 2));

	if (month < 1 || month > 12 || day > 31 || day < 1 || year > 2024) 
		return false;
	if (month == 2 && day > 29)
		return false;
	return true;
}

bool	isValueValid(float value) {
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (value > 1000) {
		std::cerr << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

void	Bitcoin::findClosestDate(std::string& date, float& value) {

	std::map<std::string, float>::const_iterator	it = _ratesData.lower_bound(date);

	if (it == _ratesData.begin()) {
		std::cout << "Error: date not found: date is prior to the first of the list => " << it->first << std::endl;
		return ;
	}
	else if (it->first == date)
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else {
		--it;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}

void	Bitcoin::displayBtcAmount(std::ifstream& inputFile) {
	
	std::string	line;
	
	while (std::getline(inputFile, line)) {
		std::istringstream	lineStream(line);
		std::string			date;
		float				value;

		if (std::getline(lineStream, date, '|')) {
			if (std::isalpha(line.c_str()[0]))
				continue;
			if (!isDateValid(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (lineStream >> value) {
				if (isValueValid(value))
					findClosestDate(date, value);
			}
			else {
				std::cerr << "Error: value is not a number" << std::endl;
				continue;
			}
		}
	}
}