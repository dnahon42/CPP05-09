/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:14 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 13:01:32 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"


class	Bureaucrat;

class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);