/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:32:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:49:45 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Form Default constructor called" << std::endl;
	this->_signed = 0;
}

Form::Form(const std::string name, unsigned int gradeToSign,
	unsigned int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form Parametized constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	this->_signed = 0;
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = other;
}
Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_signed = other._signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return (this->_name);
}

const bool &Form::getSigned() const
{
	return (this->_signed);
}

const unsigned int &Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

const unsigned int &Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	else
		this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, Form &Form)
{
	os << std::endl << Form.getName();
	os << ", is signed " << Form.getSigned();
	os << ", Grade to sign : " << Form.getGradeToSign();
	os << ", Grade to execute : " << Form.getGradeToExecute();
	return (os);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form : Grade too high");
};

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form : Grade too low");
};

const char *Form::FormException::what(void) const throw()
{
	return ("Form exception");
}