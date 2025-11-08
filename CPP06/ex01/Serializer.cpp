/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:43:44 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/06 20:03:12 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
    std::cout << "Serializer Copy Constructor called" << std::endl;
    *this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer Assignment Operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
