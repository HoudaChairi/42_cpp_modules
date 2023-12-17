/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:47 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/17 20:06:12 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <ctime>

typedef std::vector<unsigned int>	_ui_vector;
typedef std::vector<_ui_vector>		_vof_Vectors;

typedef std::list<unsigned int>										_ui_list;
typedef std::list<_ui_list>											_list_of_lists;
typedef std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >	_pend_vectors;
typedef std::list<std::pair<_ui_list , _list_of_lists::iterator> >	_pend_lists;

class PmergeMe
{
	private:
		const char**				_arg;
		size_t						_sizeofelem;
				/* Vector Container */
		_ui_vector				_vector;
		_vof_Vectors			_vectofV;
		
		_vof_Vectors			_mainCh_V;
		_vof_Vectors			_rest_V;
		_pend_vectors			_pend_V;
				/* List Container */
		_ui_list					_list;
		_list_of_lists				_lists;
		_list_of_lists				_mainCh_L;
		_list_of_lists				_rest_L;
		_pend_lists					_pend_L;
	public:
		PmergeMe();
		PmergeMe(const char **arg);
		PmergeMe(PmergeMe const & cp);
		PmergeMe &operator=(PmergeMe const & ob);
		~PmergeMe();

				/* Vector Container */
		size_t	getNumber(const char *number);
		bool	isNumber(const char *number);
		void	merge_insert_recur();
		void	create_vectors();
		void	print_vectors();
		void	sort_vectors();
		void	copy_inBase_V(_vof_Vectors _vectofV);
		void    check_pairs_V();
		void	printBaseVector();
		void	create_mainCh_Pend_rest_V();
		void	create_mainCh_pend_V();
		void	print_mainChV();
		void	print_pendV();
		void	print_restV();
		void	insert_to_mainCHV();

				/* List Container */
		void	merge_insert_list();
		void	create_lists();
		void	printBaseList();
		void	print_lists();
		void	sort_lists();
		void	copy_inBase_L(_list_of_lists _lists);
		void    check_pairs_L();
		void	create_mainCh_Pend_rest_L();
		void	create_mainCh_pend_L();
		void	print_mainChL();
		void	print_pendL();
		void	print_rest_L();
		void	insert_to_mainCH_L();
};

#endif