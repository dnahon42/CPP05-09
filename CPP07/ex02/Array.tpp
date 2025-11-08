/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:48:31 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 15:05:40 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array() : _array(NULL), _arrLength(0)
{
}

template <typename T> Array<T>::Array(unsigned int n)
{
	_array = new T[n]();
	_arrLength = n;
}

template <typename T> Array<T>::Array(const Array &src)
{
	_arrLength = src._arrLength;
	_array = new T[_arrLength];
	for (size_t i = 0; i < _arrLength; i++)
		_array[i] = src._array[i];
}

template <typename T> Array<T>::~Array()
{
	delete[] _array;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	delete[] _array;
	_arrLength = other._arrLength;
	_array = new T[_arrLength];
	for (size_t i = 0; i < _arrLength; i++)
		_array[i] = other._array[i];
	return (*this);
}

template <typename T> size_t Array<T>::size() const
{
	return (this->_arrLength);
}

template <typename T> T &Array<T>::operator[](size_t index)
{
	if (index >= this->_arrLength || index < 0)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

template <typename T> const T &Array<T>::operator[](size_t index) const
{
	if (index >= this->_arrLength || index < 0)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}