/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:40 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/13 19:08:46 by hchairi          ###   ########.fr       */
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
        for (unsigned int count = 0; count < _sizeofelem && it != _vector.end(); ++count, ++it)
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
    std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >::iterator it = _pend_V.begin();
    for (; it != _pend_V.end(); ++it)
    {
		std::cout << "[ ";
        for (_ui_vector::iterator itv = it->first.begin(); itv != it->first.end(); ++itv)
            std::cout << *itv << "  ";
		std::cout << "] ";
        
        // std::cout << std::endl;  // Add a newline after printing each vector
    }
}

void PmergeMe::print_mainChV()
{
	std::vector<_ui_vector>::iterator m_it;
	for (m_it = _mainCh_V.begin(); m_it != _mainCh_V.end(); m_it++)
	{
		std::cout << "[ "; 
		_ui_vector::iterator it;
		for (it = m_it->begin(); it != m_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}

void	PmergeMe::print_rest()
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

void PmergeMe::create_mainCh_Pend_rest()
{
	// first cheque rest
	if (_vectofV.back().size() != _sizeofelem)
	{
		_rest_V.push_back(_vectofV.back());
		_vectofV.pop_back();
	}
	//  puch first vectors in mainCh
	_mainCh_V.reserve(_vector.size());
	_mainCh_V.clear();
	_pend_V.reserve(_vector.size());
	_pend_V.clear();

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

bool comp(_ui_vector a, _ui_vector b)
{
	return (a.back() <= b.back());
}

void	PmergeMe::insert_to_mainCHV()
{
	std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >::iterator p_it;
	std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >::iterator p;
	for(p_it = _pend_V.begin(); p_it != _pend_V.end(); p_it++)
	{
		_vof_Vectors::iterator m_it;
		m_it = std::lower_bound(_mainCh_V.begin(), _mainCh_V.end(), p_it->first, comp);
		_mainCh_V.insert(m_it, p_it->first);
		for (p = _pend_V.begin(); p != _pend_V.end(); p++)
		{
			if (p->second >= m_it)
				p->second++;
		}
	} 
}



void PmergeMe::merge_insert_recur()
{
	std::cout << "#################  Part 1:	" << std::endl;
	std::cout << "sizeof: " << _sizeofelem << '\n';
	printBaseVector();
	create_vectors();
	std::cout << "BEFOR sort vvecs :	";
	print_vectors();
	
	sort_vectors();

	std::cout << std::endl;
	std::cout << "AFTER sort vvecs :	";
	print_vectors();
	
	copy_inBase_V(_vectofV);

	printBaseVector();
	std::cout << std::endl;
	
	if (_vectofV[0].size() == _vectofV[1].size())
		if (_vectofV[2].size() == _vectofV[3].size())
		{
			_sizeofelem *= 2;
			std::cout << "here: "<< _sizeofelem << '\n';
			_vectofV.clear();
			merge_insert_recur();
		}
	std::cout << "\n\nPart 2:-----------------------	" << std::endl;
	create_vectors();

	std::cout << std::endl;
	std::cout << "vector:		";
	print_vectors();
	
	create_mainCh_Pend_rest();
	
	// inseert : it's here
	insert_to_mainCHV();
	std::cout << "\nrest	:	";
	print_rest();
	if (_rest_V.size())
	{
		_mainCh_V.push_back(_rest_V.back());
		_rest_V.clear();
	}
	copy_inBase_V(_mainCh_V);
	_sizeofelem /= 2;
	
	std::cout << "\nmainChV	:	";
	print_mainChV();
	std::cout << std::endl;
	std::cout << "pendV	:	";
	print_pendV();
	_mainCh_V.clear();
	_pend_V.clear();
	_rest_V.clear();
}








/* --------------------------------- ACCESSOR --------------------------------- */

std::vector<_ui_vector> PmergeMe::getVectofV() const 
{
    return (_vectofV);
}

// std::vector<unsigned int> PmergeMe::getVector() const 
// {
//     return (_vector);
// }

// std::list<unsigned int> PmergeMe::getList() const
// {
// 	return (_list);
// }

// std::string PmergeMe::getArg() const 
// {
// 	return (_arg);	
// }
/* ************************************************************************** */