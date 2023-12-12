/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:03 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/12 12:57:56 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* --------------------------------- METHODS ---------------------------------- */

                /* ----------> print Base <---------- */
void PmergeMe::printBaseList()
{
    std::cout << std::endl;
    std::cout << "=> Base List:		";
    std::cout << "[";
    for(_ui_list::iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << "  ";
    std::cout << "]";
	std::cout << std::endl;
}

                /* ----------> create Paires <---------- */
void PmergeMe::create_lists()
{
    _list.clear();
    _ui_list::iterator it = _list.begin();
    for(; it != _list.end(); ++it)
    {
        _ui_list tmp_list;
        for (size_t j = 0; j < _sizeofelem && it != _list.end(); ++j, ++it)
        {
            tmp_list.push_back(*it);
        }
        _lists.push_back(tmp_list);
    }
}

void PmergeMe::merge_insert_list()
{
    printBaseList();
    create_lists();
    
}