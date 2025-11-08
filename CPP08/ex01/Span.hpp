/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:03:32 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 18:58:48 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class Span
{
  private:
	std::vector<int> _array;
	Span();

  public:
	Span(unsigned int n);
	Span(const Span &src);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int n);
	void addRange(size_t n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void printNumbers() const;
};

class SpanFullException : public std::exception
{
  public:
	virtual const char *what() const throw()
	{
		return (BOLD RED "Span is already full." RESET);
	}
};

class NotEnoughNumbersException : public std::exception
{
  public:
	virtual const char *what() const throw()
	{
		return (BOLD RED "There is not enough numbers to determine a span." RESET);
	}
};