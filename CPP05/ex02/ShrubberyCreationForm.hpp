/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:16 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/01 17:50:56 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class	Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);