/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:36 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/19 18:13:57 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack()
{
}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &src)
{
	*this = src;
}

template <typename T> MutantStack<T>::~MutantStack()
{
}

template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this == &other)
		return (*this);
	std::stack<T>::operator=(other);
	return (*this);
}
