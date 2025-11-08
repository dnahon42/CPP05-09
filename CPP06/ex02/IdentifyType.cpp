/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyType.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:18:57 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/06 20:11:29 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyType.hpp"

Base::~Base()
{
}

Base *Base::generate(void)
{
	int	random;

	std::srand(time(NULL));
	random = std::rand() % 3 + 1;
	std::cout << BOLD GREEN "1 = A, 2 = B, 3 = C" << std::endl;
	std::cout << BOLD CYAN "Random number is : " << random << RESET << std::endl;
	if (random == 1)
		return (new A());
	else if (random == 2)
		return (new B());
	else
		return (new C());
}

void Base::identify(Base *p)
{
	int	isA;
	int	isB;
	int	isC;
	A	*test;
	B	*test2;
	C	*test3;

	isA = 1;
	isB = 1;
	isC = 1;
	if (!p)
		return ;
	test = dynamic_cast<A *>(p);
	if (test == NULL)
		isA = 0;
	test2 = dynamic_cast<B *>(p);
	if (test2 == NULL)
		isB = 0;
	test3 = dynamic_cast<C *>(p);
	if (test3 == NULL)
		isC = 0;
	if (isA == 1)
		std::cout << YELLOW BOLD "Type is A" RESET << std::endl;
	if (isB == 1)
		std::cout << YELLOW BOLD "Type is B" RESET << std::endl;
	if (isC == 1)
		std::cout << YELLOW BOLD "Type is C" RESET << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << YELLOW BOLD "Type is A" RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << YELLOW BOLD "Type is B" RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << YELLOW BOLD "Type is C" RESET << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
}
