/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:03:31 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/19 18:02:14 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printNumbers();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	Span sp2(10000);
	sp2.addRange(10000);
	sp2.printNumbers();
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	try
	{
		sp2.addNumber(5);
	}
	catch (std::exception &e)
	{
		std::cout << BOLD YELLOW "Exception caught : " RESET << e.what() << std::endl;
	}
	try
	{
		Span small(1);
		small.addNumber(3);
		std::cout << small.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BOLD YELLOW "Exception caught : " RESET << e.what() << std::endl;
	}
	return (0);
}