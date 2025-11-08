/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:43:40 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 20:10:00 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << BOLD << GREEN << "Signing error test" << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("test", 140);
		Form contract;
		std::cout << BOLD << CYAN << bureaucrat << RESET << std::endl;
		bureaucrat.signForm(contract);
		std::cout << contract.getSigned() << RESET << std::endl << std::endl;
		// Form contracterror("Error", 155, 1);
	}
	catch (const Form::FormException &e)
	{
		std::cout << BOLD << RED << "Exception : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << BOLD << GREEN << "Signing successful test" << RESET << std::endl;
	try
	{
		Bureaucrat bureaucrat("test", 50);
		Form contract("Contract", 80, 40);
		std::cout << BOLD << CYAN << bureaucrat << std::endl;
		bureaucrat.signForm(contract);
		std::cout << contract.getSigned() << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (const Form::FormException &e)
	{
		std::cout << BOLD << RED << "Exception : " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}