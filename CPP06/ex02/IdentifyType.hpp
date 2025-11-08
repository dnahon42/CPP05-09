/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:18:58 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/06 20:07:11 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class Base
{
  public:
	virtual ~Base();
	static Base *generate(void);
	void identify(Base *p);
	void identify(Base &p);
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};