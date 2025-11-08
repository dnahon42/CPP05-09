/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:30:23 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/08 16:41:44 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(const PMergeMe &other)
{
	_queue = other._queue;
	_list = other._list;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &other)
{
	if (this != &other)
	{
		_queue = other._queue;
		_list = other._list;
	}
	return (*this);
}

PMergeMe::~PMergeMe()
{
}

void PMergeMe::parseAndAddQueue(int ac, char **av)
{
	long	num;

	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]) && arg[j] != '+' && arg[j] != '-'
				&& arg[j] != '/' && arg[j] != '*')
				throw PMergeMe::InvalidChars();
		}
		num = std::atof(arg.c_str());
		if (num < 0 || num > INT_MAX)
			throw Overflow();
		_queue.push_back(num);
	}
}

void PMergeMe::parseAndAddList(int ac, char **av)
{
	long	num;

	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]) && arg[j] != '+' && arg[j] != '-'
				&& arg[j] != '/' && arg[j] != '*')
				throw PMergeMe::InvalidChars();
		}
		num = std::atof(arg.c_str());
		if (num < 0 || num > INT_MAX)
			throw Overflow();
		_list.push_back(num);
	}
}

void PMergeMe::printBefore(void) const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _queue.size(); i++)
	{
		std::cout << _queue[i] << " ";
	}
	std::cout << std::endl;
}

void PMergeMe::printAfter(void) const
{
	std::cout << "After:  ";
	for (size_t i = 0; i < _queue.size(); i++)
	{
		std::cout << _queue[i] << " ";
	}
	std::cout << std::endl;
}


size_t PMergeMe::binarySearchDeque(const std::deque<int> &container, int value,
	size_t end)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = end;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

static void	mergePairsDeque(std::deque<std::pair<int, int> > &pairs, size_t left,
		size_t mid, size_t right)
{
	size_t	i;
	size_t	j;

	std::deque<std::pair<int, int> > temp;
	i = left;
	j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (pairs[i].first <= pairs[j].first)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}
	while (i <= mid)
		temp.push_back(pairs[i++]);
	while (j <= right)
		temp.push_back(pairs[j++]);
	for (size_t k = 0; k < temp.size(); k++)
		pairs[left + k] = temp[k];
}

static void	mergeSortPairsDeque(std::deque<std::pair<int, int> > &pairs,
		size_t left, size_t right)
{
	size_t	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		mergeSortPairsDeque(pairs, left, mid);
		mergeSortPairsDeque(pairs, mid + 1, right);
		mergePairsDeque(pairs, left, mid, right);
	}
}

void PMergeMe::mergeInsertDeque(std::deque<int> &container)
{
	bool	hasStraggler;
	int		straggler;
	size_t	next;
	size_t	currentJacob;
	size_t	prevJacob;
	size_t	idx;
	size_t	pos;

	if (container.size() <= 1)
		return ;
	// Étape 1: Pairing - créer des paires et trier chaque paire
	std::deque<std::pair<int, int> > pairs;
	hasStraggler = false;
	straggler = 0;
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}
	if (DEBUG)
	{
		std::cout << BOLD YELLOW "Pairs formed: " RESET;
		for (size_t i = 0; i < pairs.size(); i++)
		{
			std::cout << "(" << pairs[i].first << ", " << pairs[i].second
				<< ") ";
		}
		std::cout << std::endl;
	}
	if (container.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = container[container.size() - 1];
	}
	// Étape 2: Merge Sort - trier les paires selon leur premier élément
	if (pairs.size() > 1)
		mergeSortPairsDeque(pairs, 0, pairs.size() - 1);
	if (DEBUG)
	{
		std::cout << BOLD YELLOW "Pairs after sorting: " RESET;
		for (size_t i = 0; i < pairs.size(); i++)
		{
			std::cout << "(" << pairs[i].first << ", " << pairs[i].second
				<< ") ";
		}
		std::cout << std::endl;
	}
	// Étape 3: Generate Sequences - créer mainChain et pending
	std::deque<int> mainChain;
	std::deque<int> pending;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}
	if (DEBUG)
	{
		std::cout << BOLD YELLOW "Main chain initial: " RESET;
		for (size_t i = 0; i < mainChain.size(); i++)
			std::cout << mainChain[i] << " ";
		std::cout << std::endl;
		std::cout << BOLD YELLOW "Pending initial: " RESET;
		for (size_t i = 0; i < pending.size(); i++)
			std::cout << pending[i] << " ";
		std::cout << std::endl;
	}	
	// Étape 4: Insérer le premier élément de pending
	if (!pending.empty())
	{
		mainChain.insert(mainChain.begin(), pending[0]);
		pending.erase(pending.begin());
	}
	if (DEBUG)
	{
		std::cout << BOLD YELLOW "Main chain after first insert: "
			RESET;
		for (size_t i = 0; i < mainChain.size(); i++)
			std::cout << mainChain[i] << " ";
		std::cout << std::endl;
		std::cout << BOLD YELLOW "Pending after first insert: "
			RESET;
		for (size_t i = 0; i < pending.size(); i++)
			std::cout << pending[i] << " ";
		std::cout << std::endl;
	}
	// Étape 5: Générer la séquence de Jacobsthal
	std::deque<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	while (true)
	{
		next = jacobsthal[jacobsthal.size() - 1] + 2
			* jacobsthal[jacobsthal.size() - 2];
		if (next > pending.size())
			break;
		jacobsthal.push_back(next);
	}
	// Étape 6: Insérer selon l'ordre de Jacobsthal
	std::deque<bool> inserted(pending.size(), false);
	for (size_t i = 2; i < jacobsthal.size(); i++)
	{
		currentJacob = jacobsthal[i];
		prevJacob = jacobsthal[i - 1];
		// Insérer de currentJacob vers prevJacob (décroissant)
		for (size_t k = std::min(currentJacob, pending.size()); k > prevJacob
			&& k > 0; k--)
		{
			idx = k - 1;
			if (idx < pending.size() && !inserted[idx])
			{
				pos = binarySearchDeque(mainChain, pending[idx],
						mainChain.size());
				mainChain.insert(mainChain.begin() + pos, pending[idx]);
				inserted[idx] = true;
			}
		}
	}
	// Insérer les éléments restants non insérés
	for (size_t i = 0; i < pending.size(); i++)
	{
		if (!inserted[i])
		{
			pos = binarySearchDeque(mainChain, pending[i], mainChain.size());
			mainChain.insert(mainChain.begin() + pos, pending[i]);
		}
	}
	// Insérer le straggler si présent
	if (hasStraggler)
	{
		pos = binarySearchDeque(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, straggler);
	}
	container = mainChain;
}

void PMergeMe::fordJohnsonDeque(std::deque<int> &container)
{
	mergeInsertDeque(container);
}


std::list<int>::iterator PMergeMe::binarySearchList(std::list<int> &container,
	int value, size_t end)
{
	size_t	leftIdx;
	size_t	rightIdx;
	size_t	mid;

	if (container.empty() || end == 0)
		return (container.begin());
	leftIdx = 0;
	rightIdx = end;
	while (leftIdx < rightIdx)
	{
		mid = leftIdx + (rightIdx - leftIdx) / 2;
		std::list<int>::iterator midIt = container.begin();
		std::advance(midIt, mid);
		if (*midIt < value)
			leftIdx = mid + 1;
		else
			rightIdx = mid;
	}
	std::list<int>::iterator result = container.begin();
	std::advance(result, leftIdx);
	return (result);
}

// Merge pour le merge sort des paires (list)
static void	mergePairsList(std::list<std::pair<int, int> > &pairs,
		std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int,
		int> >::iterator mid, std::list<std::pair<int, int> >::iterator right)
{
	(void)pairs;
	std::list<std::pair<int, int> > temp;
	std::list<std::pair<int, int> >::iterator i = left;
	std::list<std::pair<int, int> >::iterator j = mid;
	while (i != mid && j != right)
	{
		if (i->first <= j->first)
		{
			temp.push_back(*i);
			++i;
		}
		else
		{
			temp.push_back(*j);
			++j;
		}
	}
	while (i != mid)
	{
		temp.push_back(*i);
		++i;
	}
	while (j != right)
	{
		temp.push_back(*j);
		++j;
	}
	// Copier le résultat
	std::list<std::pair<int, int> >::iterator copyIt = left;
	for (std::list<std::pair<int,
		int> >::iterator tIt = temp.begin(); tIt != temp.end(); ++tIt)
	{
		*copyIt = *tIt;
		++copyIt;
	}
}

// Merge sort récursif pour les paires (list)
static void	mergeSortPairsList(std::list<std::pair<int, int> > &pairs,
		std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int,
		int> >::iterator right, size_t size)
{
	size_t	mid;

	if (size <= 1)
		return ;
	mid = size / 2;
	std::list<std::pair<int, int> >::iterator midIt = left;
	std::advance(midIt, mid);
	mergeSortPairsList(pairs, left, midIt, mid);
	mergeSortPairsList(pairs, midIt, right, size - mid);
	mergePairsList(pairs, left, midIt, right);
}

void PMergeMe::mergeInsertList(std::list<int> &container)
{
	bool	hasStraggler;
	int		straggler;
	size_t	next;
	size_t	currentJacob;
	size_t	prevJacob;
	size_t	idx;

	if (container.size() <= 1)
		return ;
	// Étape 1: Pairing - créer des paires et trier chaque paire
	std::list<std::pair<int, int> > pairs;
	hasStraggler = false;
	straggler = 0;
	std::list<int>::iterator it = container.begin();
	while (it != container.end())
	{
		std::list<int>::iterator first = it++;
		if (it != container.end())
		{
			std::list<int>::iterator second = it++;
			if (*first > *second)
				pairs.push_back(std::make_pair(*first, *second));
			else
				pairs.push_back(std::make_pair(*second, *first));
		}
		else
		{
			hasStraggler = true;
			straggler = *first;
		}
	}
	// Étape 2: Merge Sort - trier les paires selon leur premier élément
	if (pairs.size() > 1)
		mergeSortPairsList(pairs, pairs.begin(), pairs.end(), pairs.size());
	// Étape 3: Construire mainChain et pending
	std::list<int> mainChain;
	std::list<int> pending;
	for (std::list<std::pair<int,
		int> >::iterator pIt = pairs.begin(); pIt != pairs.end(); ++pIt)
	{
		mainChain.push_back(pIt->first);
		pending.push_back(pIt->second);
	}
	// Étape 4: Insérer le premier élément de pending
	if (!pending.empty())
	{
		mainChain.push_front(pending.front());
		pending.pop_front();
	}
	// Étape 5: Générer la séquence de Jacobsthal
	std::deque<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (true)
	{
		next = jacobsthal[jacobsthal.size() - 1] + 2
			* jacobsthal[jacobsthal.size() - 2];
		if (next > pending.size())
			break;
		jacobsthal.push_back(next);
	}
	// Étape 6: Insérer selon l'ordre de Jacobsthal
	std::deque<bool> inserted(pending.size(), false);
	for (size_t i = 2; i < jacobsthal.size(); i++)
	{
		currentJacob = jacobsthal[i];
		prevJacob = jacobsthal[i - 1];
		// Insérer de currentJacob vers prevJacob (décroissant)
		for (size_t k = std::min(currentJacob, pending.size()); k > prevJacob
			&& k > 0; k--)
		{
			idx = k - 1;
			if (idx < pending.size() && !inserted[idx])
			{
				std::list<int>::iterator pendingIt = pending.begin();
				std::advance(pendingIt, idx);
				std::list<int>::iterator pos = binarySearchList(mainChain,
						*pendingIt, mainChain.size());
				mainChain.insert(pos, *pendingIt);
				inserted[idx] = true;
			}
		}
	}
	// Insérer les éléments restants non insérés
	for (size_t i = 0; i < pending.size(); i++)
	{
		if (!inserted[i])
		{
			std::list<int>::iterator pendingIt = pending.begin();
			std::advance(pendingIt, i);
			std::list<int>::iterator pos = binarySearchList(mainChain,
					*pendingIt, mainChain.size());
			mainChain.insert(pos, *pendingIt);
		}
	}
	// Insérer le straggler si présent
	if (hasStraggler)
	{
		std::list<int>::iterator pos = binarySearchList(mainChain, straggler,
				mainChain.size());
		mainChain.insert(pos, straggler);
	}
	container = mainChain;
}

void PMergeMe::fordJohnsonList(std::list<int> &container)
{
	mergeInsertList(container);
}

void PMergeMe::pMergeSort(int ac, char **av)
{
	clock_t start_deque, end_deque, start_list, end_list;
	if (ac < 2)
		return ;
	_queue.clear();
	_list.clear();
	parseAndAddQueue(ac, av);
	parseAndAddList(ac, av);
	printBefore();
	start_deque = clock();
	fordJohnsonDeque(_queue);
	end_deque = clock();
	printAfter();
	start_list = clock();
	fordJohnsonList(_list);
	end_list = clock();
	
	std::cout << "Time to process a range of " << ac
		- 1 << " elements with std::deque : " << GREEN BOLD << std::fixed << std::setprecision(5) << static_cast<double>(end_deque
		- start_deque) / CLOCKS_PER_SEC * 1000000 << " us" RESET << std::endl;
	std::cout << "Time to process a range of " << ac
		- 1 << " elements with std::list : " << GREEN BOLD << std::fixed << std::setprecision(5) << static_cast<double>(end_list
		- start_list) / CLOCKS_PER_SEC * 1000000 << " us" RESET << std::endl;
}

const char *PMergeMe::InvalidChars::what(void) const throw()
{
	return (RED BOLD "Error : Characters allowed are : * / - "
						"+ and digits" RESET);
};

const char *PMergeMe::Overflow::what(void) const throw()
{
	return (RED BOLD "Error : Overflow or negative value detected." RESET);
};
