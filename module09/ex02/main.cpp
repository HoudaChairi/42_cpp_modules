/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:01:32 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/17 20:05:16 by hchairi          ###   ########.fr       */
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
        // std::clock_t start = std::clock();
        /* ------------> vector <------------ */
        PmergeMe merge(av);
        // std::cout << "BEFOR:    ";
        // std::cout << std::endl;
        // std::cout << "AFTER :	";
        // merge.merge_insert_recur();
        // merge.printBaseVector();

        
        // double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        // std::cout << "Program took " << duration << " seconds to execute \n";
        
        merge.merge_insert_list();
        merge.printBaseList();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}