/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:01:32 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/11 18:58:02 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, const char **av)
{
    if (ac <= 1)
    {
        std::cout << "Usage: ./PmergeMe 'list of numbers'" << std::endl; 
        return (1);
    }
    try
    {
        PmergeMe merge(av);
        merge.merge_insert_recur();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}