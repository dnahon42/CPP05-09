/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:24:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/04 14:08:39 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class BitcoinExchange
{
  private:
	std::map<std::string, float> _database;

  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	bool isValidDate(const std::string &date) const;
	bool isValidValue(float value) const;
	float findClosestDate(const std::string &date) const;
	void loadDatabase(const std::string &filename);
	void processInputFile(const std::string &filename);
};