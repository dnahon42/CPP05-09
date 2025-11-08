/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:00 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/19 17:50:16 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

template <typename T> class MutantStack : public std::stack<T>
{
  private:
  public:
	MutantStack();
	MutantStack(const MutantStack &src);
	~MutantStack();

	MutantStack &operator=(const MutantStack &other);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return (this->c.begin());
	};
	iterator end()
	{
		return (this->c.end());
	};
	const_iterator begin() const
	{
		return (this->c.begin());
	};
	const_iterator end() const
	{
		return (this->c.end());
	};
};

#include "MutantStack.tpp"