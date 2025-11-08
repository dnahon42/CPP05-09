/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:24:52 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/07 15:42:16 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define DEBUG 1

class PMergeMe
{
  private:
	std::deque<int> _queue;
	std::list<int> _list;

	void parseAndAddQueue(int ac, char **av);
	void parseAndAddList(int ac, char **av);

	void fordJohnsonDeque(std::deque<int> &container);
	void fordJohnsonList(std::list<int> &container);

	void mergeInsertDeque(std::deque<int> &container);
	size_t binarySearchDeque(const std::deque<int> &container, int value,
		size_t end);

	void mergeInsertList(std::list<int> &container);
	std::list<int>::iterator binarySearchList(std::list<int> &container,
		int value, size_t end);

  public:
	PMergeMe();
	PMergeMe(const PMergeMe &other);
	PMergeMe &operator=(const PMergeMe &other);
	~PMergeMe();

	void pMergeSort(int ac, char **av);
	void printBefore(void) const;
	void printAfter(void) const;

	class InvalidChars : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class Overflow : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
};
