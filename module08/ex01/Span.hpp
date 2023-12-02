/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:24:19 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/02 16:40:38 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int        _N;
        std::vector<int>    _container;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& cp);
        Span& operator=(const Span& ob);
        ~Span();

        std::vector<int> getContainer() const;

        int     shortestSpan();
        int     longestSpan();

        void    addNumber(int num);
        void    _addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e);
};

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif