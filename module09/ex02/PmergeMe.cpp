/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:40 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/17 20:06:03 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ------------------------------- CONSTRUCTOR -------------------------------- */

PmergeMe::PmergeMe() {}

bool	PmergeMe::isNumber(const char *number)
{
	for(int i = 0; number[i]; i++)
		if (!std::isdigit(number[i]))
			throw std::runtime_error("Error");
	return true;
}

size_t	PmergeMe::getNumber(const char *number)
{
	isNumber(number);
	int num = std::atoi(number);
	if (num < 0)
		throw std::runtime_error("Error");
	return (num);
}

PmergeMe::PmergeMe(const char **arg) : _arg(arg), _sizeofelem(1)
{
	int i = 1;
	while (_arg[i])
	{
		size_t num = getNumber(_arg[i]);
		_vector.push_back(num);
		_list.push_back(num);
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe& cp) {*this = cp;}

/* -------------------------------- DESTRUCTOR -------------------------------- */

PmergeMe::~PmergeMe() {}

/* --------------------------------- OVERLOAD --------------------------------- */

PmergeMe& PmergeMe::operator=( PmergeMe const & ob)
{
	if (this != &ob)
		return (*this);
	return (*this);
}

/* --------------------------------- METHODS ---------------------------------- */

void PmergeMe::print_vectors()
{
	_vof_Vectors::iterator v_it;
	for (v_it = _vectofV.begin(); v_it != _vectofV.end(); v_it++)
	{
		std::cout << "[ "; 
		_ui_vector::iterator it;
		for (it = v_it->begin(); it != v_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}
void PmergeMe::create_vectors()
{
    _vectofV.clear();
    for (_ui_vector::iterator it = _vector.begin(); it != _vector.end(); )
    {
        _ui_vector tmp_vec;
        for (u_short count = 0; count < _sizeofelem && it != _vector.end(); ++count, ++it)
        {
            tmp_vec.push_back(*it);
        }
        _vectofV.push_back(tmp_vec);
    }
}

void PmergeMe::sort_vectors()
{
	for (size_t i = 0; i < _vectofV.size() - 1; i += 2)
	{
		if (_vectofV[i].size() ==  _vectofV[i + 1].size())
		{
			if (_vectofV[i].back() > _vectofV[i + 1].back())
				std::swap(_vectofV[i], _vectofV[i + 1]);
		}
	}
}

void PmergeMe::copy_inBase_V(_vof_Vectors _vectofV)
{
	_vector.clear();
	for (size_t i = 0; i < _vectofV.size(); i++)
	{
		_ui_vector::iterator it = _vectofV[i].begin();
		for (; it != _vectofV[i].end(); ++it) 
            _vector.push_back(*it);
	}
}

void    PmergeMe::check_pairs_V()
{
    _vof_Vectors::iterator it1= _vectofV.begin();
    _vof_Vectors::iterator it2 = _vectofV.begin();
    _vof_Vectors::iterator it3 = _vectofV.begin();
    _vof_Vectors::iterator it4 = _vectofV.begin();

    std::advance(it2, 1);
    std::advance(it3, 2);
    std::advance(it4, 3);

	if (it1 == _vectofV.end() || it2 == _vectofV.end() || it3 == _vectofV.end()
		|| it4 == _vectofV.end())
		return;

    if (it1->size() == _sizeofelem &&  it2->size() == _sizeofelem)
        if (it3->size() == _sizeofelem && it4->size()  == _sizeofelem)
        {
            _sizeofelem *= 2;
            _vectofV.clear();
            merge_insert_recur();
        }
}

void PmergeMe::printBaseVector() 
{
	std::cout << std::endl;
	std::cout << "=> Base Vector:		";
	std::cout << "[";
	for (_ui_vector::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout  << *it << "  ";
	std::cout << "]";
	std::cout << std::endl;
}

void PmergeMe::print_pendV()
{
    _pend_vectors::iterator it = _pend_V.begin();
    for (; it != _pend_V.end(); ++it)
    {
		std::cout << "[ ";
        for (_ui_vector::iterator itv = it->first.begin(); itv != it->first.end(); ++itv)
            std::cout << *itv << "  ";
		std::cout << "] ";
    }
}

void PmergeMe::print_mainChV()
{
	_vof_Vectors::iterator m_it;
	for (m_it = _mainCh_V.begin(); m_it != _mainCh_V.end(); m_it++)
	{
		std::cout << "[ "; 
		_ui_vector::iterator it;
		for (it = m_it->begin(); it != m_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}

void	PmergeMe::print_restV()
{
	_vof_Vectors::iterator r_it = _rest_V.begin();
	for(; r_it != _rest_V.end(); r_it++)
	{
		std::cout << "[ "; 
		_ui_vector::iterator it = r_it->begin();
		for(; it != r_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}

void PmergeMe::create_mainCh_pend_V()
{
	_mainCh_V.push_back(_vectofV[0]);
	_mainCh_V.push_back(_vectofV[1]);
	
	_vof_Vectors::iterator v_it = _vectofV.begin() + 2;
	for(; v_it != _vectofV.end(); v_it += 2)
	{
		if (*v_it == _vectofV.back())
		{
			_pend_V.push_back(std::make_pair(*v_it, _mainCh_V.end()));
			break;
		}
		else
		{
			_vof_Vectors::iterator m_it = _mainCh_V.insert(_mainCh_V.end(), *(v_it + 1));
			_pend_V.push_back(std::make_pair(*v_it, m_it));
		}
	}
}

void PmergeMe::create_mainCh_Pend_rest_V()
{
	if (_vectofV.back().size() != _sizeofelem)
	{
		_rest_V.push_back(_vectofV.back());
		_vectofV.pop_back();
	}
	_mainCh_V.reserve(_vector.size());
	_mainCh_V.clear();
	_pend_V.reserve(_vector.size());
	_pend_V.clear();
	create_mainCh_pend_V();
}

bool comp_V(_ui_vector a, _ui_vector b)
{
	return (a.back() <= b.back());
}

void	PmergeMe::insert_to_mainCHV()
{
	long jacob[] = {2,2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 
					43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810, 
					22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766, 
					2863311530, 5726623062, 11453246122, 22906492246, 45812984490};
	while (!_pend_V.empty())
	{
		_pend_vectors::iterator e_it = _pend_V.begin();
		_pend_vectors::iterator b_it = _pend_V.begin();
		int i = 0;
		int count = 0;
		while (b_it != _pend_V.end() && count < jacob[i] - 1)
		{
			count++;
			b_it++;
		}
		if (b_it == _pend_V.end())
			b_it--;
		while (1)
		{
			_vof_Vectors::iterator pos_m_it;
			pos_m_it = std::lower_bound(_mainCh_V.begin(), b_it->second, b_it->first, comp_V);
			_mainCh_V.insert(pos_m_it, b_it->first);
			_pend_vectors::iterator p = _pend_V.begin();
			for(; p != _pend_V.end(); p++)
			{ 
				if (p->second >= pos_m_it)
					p->second++;
			}
			_pend_V.erase(b_it);
			if (b_it == e_it)
				break;
			b_it--;
		}
		i++;
		count = 0;
	}
}


void PmergeMe::merge_insert_recur()
{
	std::cout << "#################  Part 1:	" << std::endl;
	printBaseVector();
	
	create_vectors();

	std::cout << "BEFOR sort vvecs :	";
	print_vectors();
	
	sort_vectors();

	std::cout << std::endl;
	std::cout << "AFTER sort vvecs :	";
	print_vectors();
	
	copy_inBase_V(_vectofV);
	// std::cout << "hi\n";

	printBaseVector();
	std::cout << std::endl;
	
	check_pairs_V();
	std::cout << "\n\nPart 2:-----------------------	" << std::endl;
	create_vectors();

	std::cout << std::endl;
	std::cout << "vector:		";
	print_vectors();
	
	create_mainCh_Pend_rest_V();
	
	std::cout << "\n************* create :" << std::endl;
	std::cout << "\nmainChV	:	";
	print_mainChV();
	std::cout << std::endl;
	std::cout << "pendV	:	";
	print_pendV();
	std::cout << "\nrest	:	";
	print_restV();
	
	
	insert_to_mainCHV(); 
	
	std::cout << "\n************* insert :" << std::endl;
	std::cout << "\nmainChV	:	";
	print_mainChV();
	std::cout << std::endl;
	std::cout << "pendV	:	";
	print_pendV();
	std::cout << "\nrest	:	";
	print_restV();

	if (!_rest_V.empty())
	{
		_mainCh_V.push_back(_rest_V.back());
		_rest_V.clear();
	}
	copy_inBase_V(_mainCh_V);
	_sizeofelem /= 2;
	_mainCh_V.clear();
	_pend_V.clear();
	_rest_V.clear();
}

/* ************************************************************************** */