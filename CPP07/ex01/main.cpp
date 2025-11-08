/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:35:39 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 12:39:45 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printInt(int &n)
{
	std::cout << n << " ";
}

void	printString(std::string &str)
{
	std::cout << str << " ";
}

void modifyString(std::string &str)
{
    str += "test";
}

void modifyInt(int &n)
{
    n += 10;
}

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	std::string arr2[5] = {"a", "b", "c", "d", "e"};
    
    std::cout << BOLD CYAN "Unmodified arrays" GREEN << std::endl;
	::iter(arr, 5, printInt);
	std::cout << std::endl;

	::iter(arr2, 5, printString);
	std::cout << std::endl;
    
    std::cout << CYAN "Modified arrays" GREEN << std::endl;
	::iter(arr, 5, modifyInt);
    ::iter(arr2, 5, modifyString);
    
	::iter(arr, 5, printInt);
	std::cout << std::endl;
	::iter(arr2, 5, printString);
	std::cout << RESET << std::endl;
	return (0);
}
