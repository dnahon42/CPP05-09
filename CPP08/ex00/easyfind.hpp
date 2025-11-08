/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:24:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/19 17:52:53 by dnahon           ###   ########.fr       */
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

class NumberNotFoundException : public std::exception
{
  public:
	virtual const char *what() const throw()
	{
		return ("Number not found");
	}
};

template <typename T> void easyfind(const T &container, int n);
#include "easyfind.tpp"