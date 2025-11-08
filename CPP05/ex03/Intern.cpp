/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:12:03 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/01 19:40:20 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern created by copy" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << "Intern assigned" << std::endl;
	return (*this);
}

static AForm *makePresident(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    try
    {
        std::string FormLevel[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
        AForm *(*Forms[])(std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
        for (int i = 0; i < 3; i++)
        {
            if (formName == FormLevel[i])
            {
                std::cout << "Intern creates " << formName << std::endl;
                return (Forms[i](target));
            }
        }
        throw UnknownFormException();
    }
    catch (Intern::UnknownFormException &e)
    {
        std::cout << RED BOLD << formName << " form couldn't be made because " << e.what() << RESET << std::endl;
    }
    return (NULL);
}

const char *Intern::UnknownFormException::what(void) const throw()
{
	return ("Intern : Unknown Form");
}