/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:03:29 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 17:11:01 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
	_array.reserve(n);
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	this->_array.reserve(other._array.capacity());
	this->_array = other._array;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_array.size() == this->_array.capacity())
		throw SpanFullException();
	this->_array.push_back(n);
}

unsigned int Span::shortestSpan()
{
	int	shortestSpan;

	if (this->_array.size() <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> tmp(this->_array);
	std::sort(tmp.begin(), tmp.end());
	shortestSpan = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < shortestSpan)
			shortestSpan = tmp[i] - tmp[i - 1];
	}
	return (shortestSpan);
}

unsigned int Span::longestSpan()
{
	if (this->_array.size() <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> tmp(this->_array);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

void Span::addRange(size_t n)
{
	int	value;

	if (n > this->_array.capacity() - this->_array.size())
		throw SpanFullException();
	srand(time(NULL));
	for (size_t i = 0; i < n; ++i)
	{
		value = rand() % 100;
		this->_array.push_back(value);
	}
}

void Span::printNumbers() const
{
	if (this->_array.size() < 1)
		throw NotEnoughNumbersException();
	for (size_t i = 0; i < this->_array.size(); i++)
		std::cout << BOLD CYAN "Number at index : " GREEN << i << CYAN " is : " GREEN << this->_array[i] << RESET <<std::endl;
}