/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:51:13 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 15:06:39 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
    Data *a = new Data();
    
    a->_value = 5;
    a->_literal = "abc";
    
    std::cout << BOLD CYAN "Struct before serialization and deserialization" RESET << std::endl;
    std::cout << BOLD GREEN "Memory address : " << a << std::endl;
    std::cout << "Value : " << a->_value << std::endl;
    std::cout << "Literal : " <<a->_literal << RESET << std::endl;
    
    std::cout << std::endl;
    
    uintptr_t test = Serializer::serialize(a);
    std::cout << BOLD CYAN "Serialized address" GREEN << std::endl;
    std::cout << test << RESET << std::endl;
    std::cout << std::endl;


    a = Serializer::deserialize(test);
    
    std::cout << BOLD CYAN "Struct after serialization and deserialization" RESET << std::endl;
    std::cout << BOLD GREEN "Memory address : " << a << std::endl;
    std::cout << "Value : " << a->_value << std::endl;
    std::cout << "Literal : " <<a->_literal << RESET << std::endl;
    delete a;
}