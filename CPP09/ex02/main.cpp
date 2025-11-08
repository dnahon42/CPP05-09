/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:31:09 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/08 14:50:44 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int	main(int ac, char **av)
{
	PMergeMe	pmerge;

	try
	{
		pmerge.pMergeSort(ac, av);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << RESET << std::endl;
	}
	return (0);
}
