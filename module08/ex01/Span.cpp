/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:24:15 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/02 18:18:09 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// ~~~~~~~~~~~Canonical Form~~~~~~~~~//
Span::Span() : _N(0)
{
    _container = std::vector<int>();
}

Span::Span(unsigned int N) : _N(N)
{
    _container = std::vector<int>();
}

Span::Span(const Span& cp) : _N(cp._N) 
{
    _container = cp._container;
}

Span& Span::operator=(const Span& ob)
{
    if (this != &ob)
    {
        _N = ob._N;
        _container = ob._container;
    }
    return (*this);
}

Span::~Span() {}
// ~~~~~~~~~~~Canonical Form~~~~~~~~~//

void Span::addNumber(int num)
{
    if (_N <= _container.size())
        throw std::out_of_range("Cannot add more numbers.");
    _container.push_back(num);
}

int Span::shortestSpan()
{
    std::vector<int> tmpV(_container);
    if (_container.size() < 2)
        throw std::runtime_error("we couldn't find shortest span.");
    std::sort(tmpV.begin(), tmpV.end());
    int deff = tmpV[1] - tmpV[0];
    for (size_t i = 2; i < tmpV.size(); i++) 
    {  
        if (deff >tmpV[i] - tmpV[i - 1])
            deff = tmpV[i] - tmpV[i - 1];
    }
    return (deff); 
}
int Span::longestSpan()
{
    std::vector<int> tmpV(_container);
    if (_container.size() < 2)
        throw std::runtime_error("we couldn't find longest span.");
    std::sort(tmpV.begin(), tmpV.end());
    return tmpV.back() - tmpV.front();
}

void Span::_addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
    if (_container.size() >= _N)
        throw std::out_of_range("Cannot add more numbers.");
    std::copy(b, e, std::back_inserter(_container));
    _container.resize(_N);
}

std::vector<int> Span::getContainer() const
{
    return (_container);
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    std::vector<int> v = span.getContainer();
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        os << *it << " ";
    return (os);
}
