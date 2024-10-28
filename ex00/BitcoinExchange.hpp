/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:04:59 by gdaignea          #+#    #+#             */
/*   Updated: 2024/10/28 17:00:04 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <map>
# include <sstream>
# include <string>
# include <fstream>
# include <stdlib.h>


class Bitcoin {

	private:

	std::map<std::string, float>	_ratesData;

	public:

	Bitcoin();
	Bitcoin(Bitcoin const& copy);
	~Bitcoin();

	Bitcoin&	operator=(Bitcoin const&);
	std::map<std::string, float> const&	getRatesData() const;

	void	extractData(std::ifstream& file);
	void	displayBtcAmount(std::ifstream& inputFile);
	void	findClosestDate(std::string& date, float& value);
};