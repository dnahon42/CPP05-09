/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:13 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/10 17:55:10 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Parametized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this == &src)
        return *this;
    _target = src._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "*Drilling noises*" << std::endl;
    srand(time(NULL));
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy of " << this->_target << " has failed." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
    os << "RobotomyRequestForm: " << form.getName() << ", Signed: " << form.getSigned()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Target: " << form.getTarget();
    return os;
}
