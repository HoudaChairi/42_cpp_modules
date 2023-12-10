/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:40 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/10 17:59:58 by hchairi          ###   ########.fr       */
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

void	PmergeMe::swap_vectors(size_t i)
{
	_ui_vector tempVector = _vectofV[i];
    _vectofV[i] = _vectofV[i + 1];
    _vectofV[i + 1] = tempVector;
}

void PmergeMe::sort_vectors()
{
	for (size_t i = 0; i < _vectofV.size() - 1; i += 2)
	{
		if (_vectofV[i].size() ==  _vectofV[i + 1].size())
		{
			if (_vectofV[i].back() > _vectofV[i + 1].back())
				swap_vectors(i);
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
	std::cout << std::endl << std::endl;
	std::cout << "=> Base Vector:     " << std::endl;
	std::cout << "[";
	for (_ui_vector::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout  <<  *it << "  ";
	std::cout << "]";
	std::cout << std::endl;
}

void PmergeMe::check_paires() 
{
	// for(int i = 0; i < 4; i++)
	// {
	// 	if (_vectofV[i].size() == _sizeofelem)
	// 	{
	// 		_sizeofelem *= 2;
	// 		merge_recursive();
	// 	}
	// }
	if (_vectofV[0].size() == _vectofV[1].size() == _vectofV[2].size() == _vectofV[3].size() == _sizeofelem)
	{
		_sizeofelem *= 2;
		_vectofV.clear();
		merge_recursive();
	}
}

void PmergeMe::merge_recursive()
{
	create_vectors();
	print_vectors();
	sort_vectors();
	std::cout << std::endl << std::endl;
	std::cout << "=> AFTER SORTING:    " << std::endl;
	copy_inBase_V();
	check_paires();
	std::cout << std::endl << std::endl;

	print_vectors();

	printBaseVector();
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