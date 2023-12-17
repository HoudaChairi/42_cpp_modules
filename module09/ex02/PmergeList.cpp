/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:39:03 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/17 20:05:44 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* --------------------------------- METHODS ---------------------------------- */

                /* ----------> copy Lists in Base <---------- */
void    PmergeMe::copy_inBase_L(_list_of_lists _lists)
{
    _list.erase(_list.begin(), _list.end());
    _list_of_lists::iterator it_l = _lists.begin();
    for (; it_l != _lists.end(); ++it_l) 
    {
        _ui_list::const_iterator it = it_l->begin();
        for (; it != it_l->end(); ++it) 
        {
            _list.push_back(*it);
        }
    }
}

                /* ----------> sort Lists <---------- */
void    PmergeMe::sort_lists()
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
void    PmergeMe::print_lists()
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
void    PmergeMe::printBaseList()
{
    std::cout << std::endl;
    std::cout << "=> Base List:		";
    std::cout << "[";
    for(_ui_list::iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << "  ";
    std::cout << "]";
	std::cout << std::endl;
}

                /* ----------> create Pairs <---------- */
void    PmergeMe::create_lists()
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

                /* ----------> check Pairs <---------- */
void    PmergeMe::check_pairs_L()
{
    _list_of_lists::iterator it1= _lists.begin();
    _list_of_lists::iterator it2 = _lists.begin();
    _list_of_lists::iterator it3 = _lists.begin();
    _list_of_lists::iterator it4 = _lists.begin();

    std::advance(it2, 1);
    std::advance(it3, 2);
    std::advance(it4, 3);

    if (it1 == _lists.end() || it2 == _lists.end() || it3 == _lists.end()
		|| it4 == _lists.end())
		return;

    if (it1->size() == _sizeofelem &&  it2->size() == _sizeofelem)
        if (it3->size() == _sizeofelem && it4->size()  == _sizeofelem)
        {
            _sizeofelem *= 2;
            _lists.clear();
            merge_insert_list();
        }
}
                /* ----------> print mainCH Pend Rest <---------- */
void    PmergeMe::print_mainChL()
{
	_list_of_lists::iterator m_it;
	for (m_it = _mainCh_L.begin(); m_it != _mainCh_L.end(); m_it++)
	{
		std::cout << "[ "; 
		_ui_list::iterator it;
		for (it = m_it->begin(); it != m_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
    std::cout << std::endl;
}

void    PmergeMe::print_pendL()
{
    _pend_lists::iterator it = _pend_L.begin();
    for (; it != _pend_L.end(); ++it)
    {
		std::cout << "[ ";
        for (_ui_list::iterator itv = it->first.begin(); itv != it->first.end(); ++itv)
            std::cout << *itv << "  ";
		std::cout << "] ";
    }
}

void	PmergeMe::print_rest_L()
{
	_list_of_lists::iterator r_it = _rest_L.begin();
	for(; r_it != _rest_L.end(); r_it++)
	{
		std::cout << "[ "; 
		_ui_list::iterator it = r_it->begin();
		for(; it != r_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}

                /* ----------> create mainCH Pend Rest <---------- */
void    PmergeMe::create_mainCh_pend_L()
{
    _list_of_lists::iterator it_l = _lists.begin(); 
    for(int i = 0; i < 2 && it_l != _lists.end(); i++)
    {
        _mainCh_L.push_back(*it_l);
        it_l++;
    }
    while (it_l != _lists.end())
    {
        if (*it_l == _lists.back())
        {
            _pend_L.push_back(std::make_pair(*it_l, _mainCh_L.end()));
            break;
        }
        else
        {
            _list_of_lists::iterator next_it = it_l;
            next_it++;
            _list_of_lists::iterator m_it = _mainCh_L.insert(_mainCh_L.end(), *(next_it));
            _pend_L.push_back(std::make_pair(*it_l, m_it));
            std::advance(it_l, 2);
        }
    }
} 
void    PmergeMe::create_mainCh_Pend_rest_L()
{
    if (_lists.back().size() != _sizeofelem)
	{
		_rest_L.push_back(_lists.back());
		_lists.pop_back();
	}
    create_mainCh_pend_L();
}
                /* ----------> insert to mainCH <---------- */
bool comp_L(_ui_list a, _ui_list b)
{
	return (a.back() <= b.back());
}
                
void	PmergeMe::insert_to_mainCH_L()
{
    long jacob[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 
					43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810, 
					22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766, 
					2863311530, 5726623062, 11453246122, 22906492246, 45812984490};
    while (!_pend_L.empty())
    {
        _pend_lists::iterator e_it = _pend_L.begin();
		_pend_lists::iterator b_it = _pend_L.begin();
        int i = 0;
		int count = 0;
        while (b_it != _pend_L.end() && count < jacob[i] - 1)
        {
            count++;
            b_it++;
        }
        if (b_it == _pend_L.end())
            b_it--;
        while (1)
        {
            _list_of_lists::iterator pos_m_it;
            pos_m_it = lower_bound(_mainCh_L.begin(), b_it->second, b_it->first, comp_L);
            _mainCh_L.insert(pos_m_it, b_it->first);
            _pend_L.erase(b_it);
            if (b_it == e_it)
                break;
            b_it--;
        }
        i++;
        count = 0;
    }
}
                /* ----------> recursive function <---------- */
void    PmergeMe::merge_insert_list()
{
    printBaseList();
    create_lists();
    std::cout << "BEFOR sort vvecs :	";
    print_lists();

    sort_lists();
    
    std::cout << std::endl;
	std::cout << "AFTER sort vvecs :	";
    print_lists();
    
    copy_inBase_L(_lists);
    
    printBaseList();
    std::cout << std::endl;

    check_pairs_L();
    std::cout << "\n\nPart 2:-----------------------	" << std::endl;
    create_lists();
    
    std::cout << std::endl;
	std::cout << "list:		";
    print_lists();

    create_mainCh_Pend_rest_L();

    std::cout << "\n************* create :" << std::endl;
	std::cout << "\nmainChV	:	";
    print_mainChL();
    std::cout << std::endl;
	std::cout << "pendV	:	";
    print_pendL();
    std::cout << "\nrest	:	";
	print_rest_L();

    insert_to_mainCH_L();
	
	std::cout << "\n************* insert :" << std::endl;
	std::cout << "\nmainChV	:	";
	print_mainChV();
	std::cout << std::endl;
	std::cout << "pendV	:	";
	print_pendV();
	std::cout << "\nrest	:	";
	print_restV();
    
    if (_rest_L.size())
	{
		_mainCh_L.push_back(_rest_L.back());
		_rest_L.clear();
	}
    copy_inBase_L(_mainCh_L);
    _sizeofelem /= 2;
    _lists.clear();
    _mainCh_L.clear();
    _pend_L.clear();
    _rest_L.clear();
    
}