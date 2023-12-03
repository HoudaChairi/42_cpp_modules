/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:24:22 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/03 17:50:50 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "~~~~ADD NUMBER NORMAL~~~~~" << std::endl;
        Span sp(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl << std::endl;

        std::cout << "~~ADD NUMBER BY ITERATOR~~" << std::endl;
        std::vector<int> vector(6);

        int i = 1;
        std::vector<int>::iterator it;
        for (it = vector.begin(); it != vector.end(); it++)
            *it = i++;
            
        std::cout << sp << std::endl;
        sp._addNumber(vector.begin(), vector.end());
        std::cout << sp << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
