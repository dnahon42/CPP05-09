/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:32:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/01 17:52:21 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
{
	std::cout << "AForm Default constructor called" << std::endl;
	this->_name = "Default";
	this->_gradeToSign = 1;
	this->_gradeToExecute = 1;
	this->_signed = 0;
}

AForm::AForm(const std::string name, unsigned int gradeToSign,
	unsigned int gradeToExecute)
{
	std::cout << "AForm Parametized constructor called" << std::endl;
	this->_name = name;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
	this->_signed = 0;
}

AForm::AForm(const AForm &other)
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
	this->_name = other._name;
	this->_gradeToSign = other._gradeToSign;
	this->_gradeToExecute = other._gradeToExecute;
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