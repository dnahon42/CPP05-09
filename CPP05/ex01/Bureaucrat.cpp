/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:35:39 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:51:39 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default")
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	std::cout << "Bureaucrat Parametized constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}
const unsigned int &Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
void Bureaucrat::PromoteBureaucrat(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::DemoteBureaucrat(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED BOLD << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &Bureaucrat)
{
	os << std::endl;
	os << Bureaucrat.getName();
	os << ", bureaucrat grade ";
	os << Bureaucrat.getGrade();
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat : Grade too high");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat : Grade too low");
};

const char *Bureaucrat::BureaucratException::what(void) const throw()
{
	return ("Bureaucrat exception");
}