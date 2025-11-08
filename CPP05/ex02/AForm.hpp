/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:32:57 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:50:41 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;

  public:
	AForm();
	AForm(const std::string name, unsigned int gradeToSign,
		unsigned int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

	const std::string &getName() const;
	const bool &getSigned() const;
	const unsigned int &getGradeToSign() const;
	const unsigned int &getGradeToExecute() const;
	virtual void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class AFormException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooHighException : public AFormException
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public AFormException
	{
		public:
		virtual const char *what(void) const throw();
	};
	class FormNotSignedException : public AFormException
	{
		public:
		virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, AForm &AForm);
