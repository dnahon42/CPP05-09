/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:24:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/07 15:59:59 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <climits>
#include <stack>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class RPN
{
  private:
	std::stack<int> _stack;

  public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	bool parseSyntax(std::string rpn);
	int rpn(std::string rpn);

	class RPNException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class InvalidChars : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class Overflow : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
};
