/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:19:24 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 15:11:15 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

template <typename T> void swap(T &param1, T &param2)
{
	T	tmp;

	tmp = param1;
	param1 = param2;
	param2 = tmp;
}

template <typename T> T min(T param1, T param2)
{
	if (param1 < param2)
		return (param1);
	else
		return (param2);
}

template <typename T> T max(T param1, T param2)
{
	if (param1 > param2)
		return (param1);
	else
		return (param2);
}