/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:43:40 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 15:38:01 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	b1("b1", 1);
		Bureaucrat	b2("b2", 150);
		Bureaucrat	b3("b3", 75);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm	s1("home");
		RobotomyRequestForm		r1("Bender");
		PresidentialPardonForm	p1("Fry");

		std::cout << std::endl;

		std::cout << s1 << std::endl;
		std::cout << r1 << std::endl;
		std::cout << p1 << std::endl;
		
		std::cout << std::endl;

		std::cout << CYAN BOLD "Grade too low to sign all forms" RESET << std::endl;
		b3.signForm(s1);
		b3.signForm(r1);
		b3.signForm(p1);

		std::cout << std::endl;

		std::cout << CYAN BOLD "Grade is high enough to sign all forms" RESET << std::endl;
		b1.signForm(s1);
		b1.signForm(r1);
		b1.signForm(p1);

		std::cout << std::endl;

		std::cout << s1 << std::endl;
		std::cout << r1 << std::endl;
		std::cout << p1 << std::endl;

		std::cout << std::endl;

		std::cout << CYAN BOLD "Grade too low to execute any forms" RESET << std::endl;
		b2.executeForm(s1);
		b2.executeForm(r1);
		b2.executeForm(p1);

		std::cout << std::endl;

		std::cout << CYAN BOLD "Grade too low to execute all forms" RESET << std::endl;
		b3.executeForm(s1);
		b3.executeForm(r1);
		b3.executeForm(p1);

		std::cout << std::endl;

		std::cout << CYAN BOLD "Grade high enough to execute all forms" RESET << std::endl;
		b1.executeForm(s1);
		b1.executeForm(r1);
		b1.executeForm(p1);
		
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED BOLD "Exception caught in main: " << e.what() << RESET << std::endl;
	}
	return (0);
}