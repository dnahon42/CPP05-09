/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:30:23 by dnahon            #+#    #+#             */
/*   Updated: 2025/11/07 16:01:33 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN()
{
}

int RPN::rpn(std::string rpn)
{
	long	top;
	long	prev;

	prev = 0;
	top = 0;
	rpn.erase(remove_if(rpn.begin(), rpn.end(), isspace), rpn.end());
	if (parseSyntax(rpn) == 0)
		throw InvalidChars();
	for (size_t i = 0; i < rpn.size(); i++)
	{
		if (isdigit(rpn[i]))
		{
			_stack.push(rpn[i] - '0');
			continue ;
		}
		if (rpn[i] == '+')
		{
			if (_stack.size() <= 1)
				throw RPNException();
			top = _stack.top();
			_stack.pop();
			prev = _stack.top();
			_stack.pop();
			// std::cout << "Top value is : " << top << " prev value is : " << prev;
			top = prev + top;
			if (top > INT_MAX || top < INT_MIN)
				throw Overflow();
			_stack.push(top);
			// std::cout << " New top value is : " << _stack.top() << " Stack size is : " << _stack.size() << std::endl;
			continue ;
		}
		if (rpn[i] == '-')
		{
			if (_stack.size() <= 1)
				throw RPNException();
			top = _stack.top();
			_stack.pop();
			prev = _stack.top();
			_stack.pop();
			// std::cout << "Top value is : " << top << " prev value is : " << prev;
			top = prev - top;
			if (top > INT_MAX || top < INT_MIN)
				throw Overflow();
			_stack.push(top);
			// std::cout << " New top value is : " << _stack.top() << " Stack size is : " << _stack.size() << std::endl;
			continue ;
		}
		if (rpn[i] == '*')
		{
			if (_stack.size() <= 1)
				throw RPNException();
			top = _stack.top();
			_stack.pop();
			prev = _stack.top();
			_stack.pop();
			// std::cout << "Top value is : " << top << " prev value is : " << prev;
			top = prev * top;
			if (top > INT_MAX || top < INT_MIN)
				throw Overflow();
			_stack.push(top);
			// std::cout << " New top value is : " << _stack.top() << " Stack size is : " << _stack.size() << std::endl;
			continue ;
		}
		if (rpn[i] == '/')
		{
			if (_stack.size() <= 1)
				throw RPNException();
			top = _stack.top();
			_stack.pop();
			prev = _stack.top();
			_stack.pop();
			// std::cout << "Top value is : " << top << " prev value is : " << prev;
			top = prev / top;
			if (top > INT_MAX || top < INT_MIN)
				throw Overflow();
			_stack.push(top);
			// std::cout << " New top value is : " << _stack.top() << " Stack size is : " << _stack.size() << std::endl;
			continue ;
		}
	}
	return (_stack.top());
}

bool RPN::parseSyntax(std::string rpn)
{
	for (size_t i = 0; i < rpn.size(); i++)
	{
		if (rpn[i] != '*' && rpn[i] != '/' && rpn[i] != '+' && rpn[i] != '-'
			&& isdigit(rpn[i]) == 0)
		{
			return (false);
		}
	}
	return (true);
}

const char *RPN::RPNException::what(void) const throw()
{
	return (RED BOLD "Mathematical expression invalid" RESET);
};

const char *RPN::InvalidChars::what(void) const throw()
{
	return (RED BOLD "Error : Characters allowed are : * / - "
						"+ and digits" RESET);
};

const char *RPN::Overflow::what(void) const throw()
{
	return (RED BOLD "Error : The result of an RPN cannot go above INT_MAX or below INT_MIN." RESET);
};