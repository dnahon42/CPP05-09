/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:31:09 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/07 15:43:19 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <inverted Polish mathematical expression>" << std::endl;
		return (1);
	}
	try
	{
		std::cout << rpn.rpn(av[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << RESET << std::endl;
	}
	return (0);
}
