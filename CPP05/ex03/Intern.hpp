/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:12:04 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/01 19:21:23 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(const Intern &src);
    ~Intern();

    Intern &operator=(const Intern &src);

    AForm *makeForm(std::string formName, std::string target);

    class UnknownFormException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};