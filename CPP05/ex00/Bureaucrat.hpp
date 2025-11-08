/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:14:08 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:43:30 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

class Bureaucrat
{
  private:
	const std::string _name;
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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &Bureaucrat);

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