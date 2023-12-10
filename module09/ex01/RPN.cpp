/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:39:13 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/09 11:19:59 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ------------------------------- CONSTRUCTOR -------------------------------- */

RPN::RPN() {}

RPN::RPN(const std::string& form) : _form(form)
{
	unsigned int i = 0;
	while (i < _form.length())
	{
		if (std::isdigit(_form[i]))
			_stack.push(std::string(1, _form[i]));
		else if (std::isspace(_form[i]))
			;
		else if (isOp(_form[i]))
			calcul(_form[i]);
		else
			throw std::runtime_error("Invalid format!");
		i++;
	}
}

bool	RPN::isOp(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

RPN::RPN(const RPN & cp) {*this = cp;}

/* -------------------------------- DESTRUCTOR -------------------------------- */

RPN::~RPN() {}


/* --------------------------------- OVERLOAD --------------------------------- */

RPN& RPN::operator=(const RPN& ob)
{
	if ( this != &ob )
		return *this;	
	return *this;
}

/* --------------------------------- METHODS ---------------------------------- */

void RPN::calcul(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Invalid format!");
	short a = std::atoi(_stack.top().c_str());
	_stack.pop();
	short b = std::atoi(_stack.top().c_str());
	_stack.pop();
	switch (op)
	{
		case '+':
			_stack.push(std::to_string(b + a).c_str());
			break;
		case '-':
			_stack.push(std::to_string(b - a).c_str());
			break;
		case '/':
			_stack.push(std::to_string(b / a).c_str());
			break;
		case '*':
			_stack.push(std::to_string(b * a).c_str());
			break;
	}
}

/* --------------------------------- ACCESSOR --------------------------------- */
std::stack<std::string> RPN::getStack() const 
{
    return (_stack);
}

int RPN::getResult()
{
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid format!");
	return std::atoi(_stack.top().c_str());
}

/* ************************************************************************** */