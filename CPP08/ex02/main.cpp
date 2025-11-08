/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:28 by dnahon            #+#    #+#             */
/*   Updated: 2025/10/19 18:16:19 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	std::cout << BOLD CYAN "=== Test 1: Basic MutantStack Operations ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << BOLD GREEN "Top element:" RESET << std::endl;
		std::cout << BOLD YELLOW << mstack.top() << RESET << std::endl;
		mstack.pop();
		std::cout << BOLD GREEN "Stack size after pop:" RESET << std::endl;
		std::cout << BOLD YELLOW << mstack.size() << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << BOLD GREEN "Stack elements:" RESET << std::endl;
		while (it != ite)
		{
			std::cout << BOLD YELLOW << *it << RESET << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << BOLD CYAN "=== Test 2: Reverse Iteration ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 0; i < 10; i++)
			mstack.push(i);

		std::cout << BOLD GREEN "Forward iteration:" RESET << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;

		std::cout << BOLD GREEN "Reverse iteration:" RESET << std::endl;
		MutantStack<int>::iterator it = mstack.end();
		while (it != mstack.begin())
		{
			--it;
			std::cout << BOLD YELLOW << *it << " " RESET;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << BOLD CYAN "=== Test 3: Copy Constructor ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		MutantStack<int> copy(mstack);
		std::cout << BOLD GREEN "Original stack:" RESET << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;

		std::cout << BOLD GREEN "Copied stack:" RESET << std::endl;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;
	}

	std::cout << std::endl << BOLD CYAN "=== Test 4: Assignment Operator ===" RESET << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(10);
		mstack1.push(20);
		mstack1.push(30);

		MutantStack<int> mstack2;
		mstack2 = mstack1;

		std::cout << BOLD GREEN "Stack 1:" RESET << std::endl;
		for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;

		std::cout << BOLD GREEN "Stack 2 (assigned from stack 1):" RESET << std::endl;
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;
	}

	std::cout << std::endl << BOLD CYAN "=== Test 5: MutantStack with Strings ===" RESET << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("from");
		mstack.push("MutantStack");

		std::cout << BOLD GREEN "String stack:" RESET << std::endl;
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;
	}

	std::cout << std::endl << BOLD CYAN "=== Test 6: Comparison with std::list ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		std::list<int> lst;

		for (int i = 1; i <= 5; i++)
		{
			mstack.push(i * 10);
			lst.push_back(i * 10);
		}

		std::cout << BOLD GREEN "MutantStack:" RESET << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;

		std::cout << BOLD GREEN "std::list:" RESET << std::endl;
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;
	}

	std::cout << std::endl << BOLD CYAN "=== Test 7: Const Iterator ===" RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(100);
		mstack.push(200);
		mstack.push(300);

		const MutantStack<int> const_mstack(mstack);
		std::cout << BOLD GREEN "Const stack iteration:" RESET << std::endl;
		for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
			std::cout << BOLD YELLOW << *it << " " RESET;
		std::cout << std::endl;
	}

	return (0);
}