/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:26:33 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/02 19:55:14 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::cout << "~~~~~~~~~~~~~~~ Vector ~~~~~~~~~~~~~~~" << std::endl;
    std::vector<int> vector(5);
    int i = 1;
    std::vector<int>::iterator it;
    for (it = vector.begin(); it != vector.end(); it++)
    {
        *it = i++;
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    try
    {
        easyfind(vector, 1);
        easyfind(vector, 6);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    std::cout << std::endl;
    
    std::cout << "~~~~~~~~~~~~~~~ Deque ~~~~~~~~~~~~~~~" << std::endl;
    std::deque<int> d(5);
    int j = 1;
    std::deque<int>::iterator it2;
    for (it2 = d.begin(); it2 != d.end(); it2++)
    {
        *it2 = j++;
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    try
    {
        easyfind(d, 3);
        easyfind(d, 33);

    } 
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    return (0);
}
