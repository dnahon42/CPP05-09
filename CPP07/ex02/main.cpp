/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:15:31 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 14:19:08 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

int	main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //

    Array<std::string> strings(MAX_VAL);
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        if (value % 3 + 1 == 1)
            strings[i] = "a";
        else if (value % 3 + 1 == 2)
            strings[i] = "b";
        else if (value % 3 + 1 == 3)
            strings[i] = "c";
    }
    for (int i = 0; i < 20; i++)
    {
        std::cout << strings[i] << std::endl;
    }
    std::cout << "Size of string array is : " << strings.size() << std::endl;
	return (0);
}