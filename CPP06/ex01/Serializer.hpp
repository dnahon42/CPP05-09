/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:11:38 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 15:06:12 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

typedef struct Data
{
	int	_value;
	std::string _literal;
}		Data;

class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);
	~Serializer();

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
