/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:31:09 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/02 17:48:46 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	btcExchange;

	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
		return (1);
	}
	btcExchange.loadDatabase("data.csv");
	btcExchange.processInputFile(av[1]);
	return (0);
}
