/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:40 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/11 17:28:29 by hchairi          ###   ########.fr       */
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
	std::vector<_ui_vector>::iterator v_it;
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
	for(unsigned int i = 0; i < _vector.size(); i += _sizeofelem)
	{
		_ui_vector tmp_vec;
		for (unsigned int j = 0; j < _sizeofelem && i + j < _vector.size(); j++)
		{
			tmp_vec.push_back(_vector[i + j]);
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

void PmergeMe::copy_inBase_V()
{
	_vector.clear();
	for (size_t i = 0; i < _vectofV.size(); i++)
	{
		for (_ui_vector::iterator it = _vectofV[i].begin(); it != _vectofV[i].end(); ++it) 
            _vector.push_back(*it);
	}
}

void PmergeMe::printBaseVector() 
{
	std::cout << std::endl;
	std::cout << "=> Base Vector:		";
	std::cout << "[";
	for (_ui_vector::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout  <<  *it << "  ";
	std::cout << "]";
	std::cout << std::endl;
}

void PmergeMe::print_pendV()
{
    std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >::iterator it = _vofV_pend.begin();
    for (; it != _vofV_pend.end(); ++it)
    {
        for (_ui_vector::iterator itv = it->first.begin(); itv != it->first.end(); ++itv)
            std::cout << *itv << "  ";
        
        std::cout << std::endl;  // Add a newline after printing each vector
    }
}

void PmergeMe::print_mainChV()
{
	std::vector<_ui_vector>::iterator m_it;
	for (m_it = _vofV_mainCh.begin(); m_it != _vofV_mainCh.end(); m_it++)
	{
		std::cout << "[ "; 
		_ui_vector::iterator it;
		for (it = m_it->begin(); it != m_it->end() - 1; it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}

void	PmergeMe::print_rest()
{
	_vof_Vectors::iterator r_it = _rest.begin();
	for(; r_it != _rest.end(); r_it++)
	{
		std::cout << "[ "; 
		_ui_vector::iterator it = r_it->begin();
		for(; it != r_it->end(); it++)
			std::cout << *it << " ";
		std::cout << "] ";
	}
}


void PmergeMe::mainCh_Pend_rest()
{
	// first cheque rest
	if (_vectofV.back().size() != _sizeofelem)
	{
		_rest.push_back(_vectofV.back());
		_vectofV.pop_back();
	}
	//  puch first vectors in mainCh
	_vofV_mainCh.push_back(_vectofV[0]);
	_vofV_mainCh.push_back(_vectofV[1]);
	_vof_Vectors::iterator v_it = _vectofV.begin() + 2;
	for(; v_it != _vectofV.end(); v_it += 2)
	{
		if (*v_it == _vectofV.back())
			_vofV_pend.push_back(std::make_pair(*v_it, _vofV_mainCh.end())); // _vectofV[0]
		else
		{
			_vof_Vectors::iterator m_it = _vofV_mainCh.insert(_vofV_mainCh.end(), *(v_it + 1));
			_vofV_pend.push_back(std::make_pair(*v_it,m_it));
		}
	}
}


void PmergeMe::merge_insert_recur()
{
	std::cout << "Part 1:	" << std::endl;
	std::cout << "sizeof: " << _sizeofelem << '\n';
	printBaseVector();
	create_vectors();
	std::cout << "BEFOR sort vvecs :	";
	print_vectors();
	
	sort_vectors();

	std::cout << std::endl;
	std::cout << "AFTER sort vvecs :	";
	print_vectors();
	
	copy_inBase_V();

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
	std::cout << "\nPart 2:	" << std::endl;
	_vectofV.clear();
	create_vectors();
	mainCh_Pend_rest();
	// printBaseVector();
	// print_vectors();
	std::cout << std::endl;
	std::cout << "print_pendV	:	";
	print_pendV();
	std::cout << std::endl;
	std::cout << "\nprint_mainChV	:	";
	print_mainChV();
	std::cout << "\nprint_rest	:	";
	print_rest();
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