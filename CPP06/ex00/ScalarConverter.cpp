/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:16:19 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/17 15:18:21 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Assignment Operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

static int	edgecases(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "int: nan" << std::endl;
		return (1);
	}
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "int: +inf" << std::endl;
		return (1);
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inf" << std::endl;
		std::cout << "int: -inff" << std::endl;
		return (1);
	}
	return (0);
}

static std::string getType(const std::string &literal)
{
	size_t	i;
	bool	isInt;
	bool	isFloat;
	size_t	dots;

	if (literal.size() == 1 && !isdigit(literal[0]))
		return ("char");
	i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	isInt = true;
	for (; i < literal.size(); ++i)
	{
		if (!isdigit(literal[i]))
		{
			isInt = false;
			break ;
		}
	}
	if (isInt)
		return ("int");
	i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	isFloat = true;
	if (literal[literal.size() - 1] != 'f')
		isFloat = false;
	dots = 0;
	for (; i < literal.size() - 2; ++i)
	{
		if (literal[i] == '.')
			dots++;
		else if (!isdigit(literal[i]))
		{
			isFloat = false;
			break ;
		}
	}
	if (isFloat && dots == 1)
		return ("float");
	i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	bool isDouble = true;
	dots = 0;
	for (; i < literal.size() - 1; ++i)
	{
		if (literal[i] == '.')
			dots++;
		else if (!isdigit(literal[i]))
		{
			isDouble = false;
			break ;
		}
	}
	if (isDouble && dots == 1)
		return ("double");
	return ("invalid");
}

static void impossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return ;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Error: Empty string provided." << std::endl;
		return ;
	}
	if (edgecases(literal) == 1)
		return ;
	std::string type = getType(literal);
	if (type == "invalid")
	{
		std::cout << "Error : Invalid input" << std::endl;
		return ;
	}
	if (literal.size() > 308)
		return (impossible());
	if (literal.size() == 1 && type == "char")
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}
	double value = std::atof(literal.c_str());
	std::cout << "char: ";
	if ((value > 0 && value < 32) || (value > 126 && value < 256))
		std::cout << "Non displayable" << std::endl;
	else if (value > 127 || value < 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: ";
	if (value > INT_MAX || value < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}
