/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:30:23 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/04 13:50:02 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	int month;
	int day;
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return (false);
		month = std::atoi(date.substr(5, 6).c_str());
		if (month > 12 || month < 1)
			return (false);
		day = std::atoi(date.substr(8, 9).c_str());
		if (month % 2 == 0)
		{
			if (day > 30 || day < 0)
				return (false);
		}
		else if (month % 2 != 0)
		{
			if (day > 31 || day < 0)
				return (false);
		}
	}
	return (true);
}

bool BitcoinExchange::isValidValue(float value) const
{
	return (value >= 0.0f && value <= 1000.0f);
}

float BitcoinExchange::findClosestDate(const std::string &date) const
{
	std::map<std::string,
		float>::const_iterator it = _database.upper_bound(date);
	if (it == _database.begin())
		return (-1);
	--it;
	return (it->second);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	size_t	commaPos;
	float	value;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open database file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue ;
		std::string date = line.substr(0, commaPos);
		value = std::atof(line.substr(commaPos + 1).c_str());
		_database[date] = value;
	}
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
	size_t	pipePos;
	float	value;
	float	rate;
	float	convertedValue;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << BOLD RED "Error: Could not open input file." RESET << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << BOLD RED "Error: Invalid line format." RESET << std::endl;
			continue ;
		}
		std::string date = line.substr(0, pipePos - 1);
		value = std::atof(line.substr(pipePos + 2).c_str());
		if (!isValidDate(date))
		{
			std::cerr << BOLD RED "Error: Invalid date => " << date << RESET << std::endl;
			continue ;
		}
		if (!isValidValue(value))
		{
			std::cerr << BOLD RED "Error: Invalid value => " << value << RESET << std::endl;
			continue ;
		}
		rate = findClosestDate(date);
		if (rate < 0)
		{
			std::cerr << BOLD RED "Error: No exchange rate available for date => " << date << RESET << std::endl;
			continue ;
		}
		convertedValue = value * rate;
		std::cout << date << " => " << value << " = " << convertedValue << std::endl;
	}
}
