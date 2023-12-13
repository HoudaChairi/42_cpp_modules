/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:03 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/13 12:25:01 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* --------------------------------- METHODS ---------------------------------- */

                /* ----------> copy Lists in Base <---------- */
// void PmergeMe::copy_inBase_L(_list_of_lists _lists)
// {
//     // _list.erase(_list.begin(), _list.end());
//     _list.clear();
//     _list_of_lists::iterator it_l = _lists.begin(); 
//     for (; it_l != _lists.end(); ++it_l)
//     {
//         _ui_list::iterator it = _list.begin();
//         // for (; it != _list.end(); ++it)
//         // {
//         //     _list.push_back(*it);
//         //     std::cout << "checcck\n";
            
//         // }
//         while (std::distance(it, _list.end()) >= 2)
//         {
        
//         }
//     }
// }

                /* ----------> sort Lists <---------- */
void PmergeMe::sort_lists()
{
    _list_of_lists::iterator it = _lists.begin();
    while (std::distance(it, _lists.end()) >= 2)
    {
        _list_of_lists::iterator tmp_it = it;
        tmp_it++;
        if (it->size() == tmp_it->size())
        {
            if (it->back() > tmp_it->back())
                std::swap(*it, *tmp_it);
        }
        std::advance(it, 2);
    }
}
                /* ----------> print Lists <---------- */
void PmergeMe::print_lists()
{
    _list_of_lists::iterator it_l;
    for(it_l = _lists.begin(); it_l != _lists.end(); it_l++)
    {
        std::cout << "[ "; 
        _ui_list::iterator it;
        for (it = it_l->begin(); it != it_l->end(); it++)
            std::cout << *it << " ";
        std::cout << "] ";
    }
}

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
    _lists.clear();

    for (_ui_list::iterator it = _list.begin(); it != _list.end(); )
    {
        _ui_list tmp_list;
        for (unsigned int c = 0; c < _sizeofelem && it != _list.end(); ++c, ++it)
            tmp_list.push_back(*it);
        _lists.push_back(tmp_list);
    }
}



void PmergeMe::merge_insert_list()
{
    printBaseList();
    create_lists();
    std::cout << "BEFOR sort vvecs :	";
    print_lists();

    sort_lists();
    
    std::cout << std::endl;
	std::cout << "AFTER sort vvecs :	";
    print_lists();
    
    // copy_inBase_L(_lists);
    printBaseList();
    std::cout << std::endl;
}