/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:26:33 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/02 17:25:56 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vector(5);
        int i = 1;
        std::vector<int>::iterator it;
        for (it = vector.begin(); it != vector.end(); it++)
            *it = i++;

        for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        easyfind(vector, 3);
        easyfind(vector, 33);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    return (0);
}
