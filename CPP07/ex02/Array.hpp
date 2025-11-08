/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:49:10 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 15:15:35 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

template <typename T> class Array
{
  private:
	T *_array;
	size_t _arrLength;

  public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	Array &operator=(const Array &other);
	T &operator[](size_t index);
	const T &operator[](size_t index) const;

	size_t size() const;
};

#include "Array.tpp"