/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:14:08 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/06 20:15:30 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class AForm;

class Bureaucrat
{
  private:
	std::string _name;
	unsigned int _grade;

  public:
	Bureaucrat();
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	const unsigned int &getGrade() const;
	void PromoteBureaucrat();
	void DemoteBureaucrat();
	void signForm(AForm &Aform);
	void executeForm(AForm const & Aform);

	class BureaucratException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooHighException : public BureaucratException
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public BureaucratException
	{
		public:
		virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &Bureaucrat);
