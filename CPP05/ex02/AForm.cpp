/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:32:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:53:40 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "AForm Default constructor called" << std::endl;
	this->_signed = 0;
}

AForm::AForm(const std::string name, unsigned int gradeToSign,
	unsigned int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm Parametized constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	this->_signed = 0;
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = other;
}
AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_signed = other._signed;
	return (*this);
}

const std::string &AForm::getName() const
{
	return (this->_name);
}

const bool &AForm::getSigned() const
{
	return (this->_signed);
}

const unsigned int &AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

const unsigned int &AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	else
		this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, AForm &AForm)
{
	os << std::endl << AForm.getName();
	os << ", is signed " << AForm.getSigned();
	os << ", Grade to sign : " << AForm.getGradeToSign();
	os << ", Grade to execute : " << AForm.getGradeToExecute();
	return (os);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm : Grade too high");
};

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm : Grade too low");
};

const char *AForm::AFormException::what(void) const throw()
{
	return ("AForm exception");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm : Form not signed");
};