/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:16:20 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/06 19:39:33 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <climits>
#include <exception>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();

  public:
	static void convert(const std::string &literal);
};
