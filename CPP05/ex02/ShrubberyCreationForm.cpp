/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:15 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/01 17:54:54 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Parametized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this == &src)
        return *this;
    _target = src._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error: Could not open file " << this->_target + "_shrubbery" << std::endl;
        return;
    }
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
    os << "ShrubberyCreationForm: " << form.getName() << ", Signed: " << form.getSigned()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Target: " << form.getTarget();
    return os;
}
