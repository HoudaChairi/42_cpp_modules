/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:47 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/11 19:48:16 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>

typedef std::vector<unsigned int>	_ui_vector;
typedef std::vector<_ui_vector>		_vof_Vectors;
// typedef std::list<unsigned int> _ui_list;

class PmergeMe
{
	private:
		_ui_vector				_vector;
		_vof_Vectors			_vectofV;
		
		_vof_Vectors			_vofV_mainCh;
		std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >	_vofV_pend;
		_vof_Vectors			_rest;

		// _ui_list	_list;
		// std::list<_ui_list>		_list;
		const char**				_arg;
		size_t						_sizeofelem;
	public:
		PmergeMe();
		PmergeMe(const char **arg);
		PmergeMe(PmergeMe const & cp);
		PmergeMe &operator=(PmergeMe const & ob);
		~PmergeMe();

		// std::vector<unsigned int> getVector() const;
		// std::list<unsigned int> getList() const;
		// std::string getArg() const;
		std::vector<_ui_vector> getVectofV() const;
		size_t	getNumber(const char *number);
		bool	isNumber(const char *number);
		void	merge_insert_recur();
		void	create_vectors();
		void	print_vectors();
		void	sort_vectors();
		void	copy_inBase_V(_vof_Vectors _vectofV);
		void	printBaseVector(); // remove or modifier
		void	create_mainCh_Pend_rest();
		void	print_mainChV();
		void	print_pendV();
		void	print_rest();

};


#endif