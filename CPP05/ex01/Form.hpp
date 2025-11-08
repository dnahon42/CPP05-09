/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:32:57 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:47:15 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class	Bureaucrat;

class Form
{
  private:
	const std::string _name;
	bool _signed;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;

  public:
	Form();
	Form(const std::string name, unsigned int gradeToSign,
		unsigned int gradeToExecute);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	const std::string &getName() const;
	const bool &getSigned() const;
	const unsigned int &getGradeToSign() const;
	const unsigned int &getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);

	class FormException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooHighException : public FormException
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public FormException
	{
		public:
		virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Form &Form);
