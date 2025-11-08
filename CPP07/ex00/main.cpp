/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:35:39 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/09 15:11:08 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int value1 = 10;
	int value2 = 15;

	std::string string1 = "chaine1";
	std::string string2 = "chaine2";

	std::cout << BOLD CYAN "SWAP" RESET << std::endl;
	std::cout << std::endl;

	std::cout << BOLD YELLOW "INT" RESET << std::endl;
	std::cout << CYAN BOLD "Values before swap" GREEN << std::endl;
	std::cout << "value1 : " << value1 << std::endl;
	std::cout << "value2 : " << value2 << std::endl;
	::swap(value1, value2);
	std::cout << CYAN BOLD "Values after swap" GREEN << std::endl;
	std::cout << "value1 : " << value1 << std::endl;
	std::cout << "value2 : " << value2 << std::endl;

	std::cout << std::endl;

	std::cout << BOLD YELLOW "STRING" RESET << std::endl;
	std::cout << CYAN BOLD "Values before swap" GREEN << std::endl;
	std::cout << "string1 : " << string1 << std::endl;
	std::cout << "string2 : " << string2 << std::endl;
	::swap(string1, string2);
	std::cout << CYAN BOLD "Values after swap" GREEN << std::endl;
	std::cout << "string1 : " << string1 << std::endl;
	std::cout << "string2 : " << string2 << RESET << std::endl;

	std::cout << std::endl;
	std::cout << BOLD CYAN "MIN" RESET << std::endl;
	std::cout << std::endl;

	std::cout << BOLD YELLOW "INT" RESET << std::endl;
	std::cout << BOLD GREEN "Min value between " << value1 << " and " << value2;
	std::cout << " is : " << ::min(value1, value2) << std::endl;
	std::cout << BOLD YELLOW "STRING" RESET << std::endl;
	std::cout << BOLD GREEN "Min value between " << string1 << " and " << string2;
	std::cout << " is : " << ::min(string1, string2) << std::endl;

	std::cout << std::endl;
	std::cout << BOLD CYAN "MAX" RESET << std::endl;
	std::cout << std::endl;

	std::cout << BOLD YELLOW "INT" RESET << std::endl;
	std::cout << BOLD GREEN "Max value between " << value1 << " and " << value2;
	std::cout << " is : " << ::max(value1, value2) << std::endl;
	std::cout << BOLD YELLOW "STRING" RESET << std::endl;
	std::cout << BOLD GREEN "Max value between " << string1 << " and " << string2;
	std::cout << " is : " << ::max(string1, string2) << RESET << std::endl;
}