/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:01:32 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/18 12:45:04 by hchairi          ###   ########.fr       */
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
        /* ------------------------>    vector  <------------------------ */
        PmergeMe merge(av);
        
        std::cout << "Before:    ";
        merge.printBaseVector();
        
        std::clock_t start = std::clock();
        merge.merge_insert_recur();
        std::clock_t end = std::clock();
        
        std::cout << "After:     ";   
        merge.printBaseVector();
        
        std::cout << "Time to process a range of " << ac - 1;
        std::cout <<  " elements : " << end - start << " us " << std::endl;
        
        merge.setSize(1);
        /* ------------------------>    list    <------------------------ */
        start = std::clock();
        merge.merge_insert_list();
        end = std::clock();
        // std::cout << "After:     ";   
        // merge.printBaseVector();
        std::cout << "Time to process a range of " << ac - 1;
        std::cout << " elements : " << end - start << " us " << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}