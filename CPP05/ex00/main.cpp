/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:43:40 by dnahon            #+#    #+#             */
/*   Updated: 2025/09/11 17:27:18 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

int	main(void)
{
	Bureaucrat bureaucrat("test", 140);
	Bureaucrat bureaucrat2("test", 10);
	std::cout << std::endl << BOLD << GREEN << "Demote test" << RESET << std::endl;
	try
	{
		std::cout << BOLD << CYAN << bureaucrat;
		for (int i = 0; i < 10; i++)
			bureaucrat.DemoteBureaucrat();
		std::cout << bureaucrat << std::endl;
		bureaucrat.DemoteBureaucrat();
	}
	catch (const BureaucratException &e)
	{
		std::cout << BOLD << RED << "Exception : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << BOLD << GREEN << "Promote test" << RESET << std::endl;
	try
	{
		std::cout << BOLD << CYAN << bureaucrat2;
		for (int i = 0; i < 9; i++)
			bureaucrat2.PromoteBureaucrat();
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.PromoteBureaucrat();
	}
	catch (const BureaucratException &e)
	{
		std::cout << std::endl << BOLD << RED << "Exception : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "Assignment test" << RESET << std::endl;
	try
	{
		std::cout << BOLD << CYAN << bureaucrat2 << std::endl;
		bureaucrat2 = bureaucrat;
		std::cout << BOLD << CYAN << bureaucrat2 << std::endl;
		bureaucrat2.DemoteBureaucrat();
	}
	catch (const BureaucratException &e)
	{
		std::cout << BOLD << RED << "Exception : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}