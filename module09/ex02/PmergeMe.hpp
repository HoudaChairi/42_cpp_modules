/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:47 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/13 13:05:08 by hchairi          ###   ########.fr       */
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

typedef std::list<unsigned int>		_ui_list;
typedef std::list<_ui_list>			_list_of_lists;

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
		std::vector<std::pair<_ui_vector, _vof_Vectors::iterator> >	_pend_V;
				/* List Container */
		_ui_list					_list;
		_list_of_lists				_lists;
		_list_of_lists				_mainCh_L;
		_list_of_lists				_rest_L;
		std::list<std::pair<_ui_list, _list_of_lists::iterator> >	_pend_L;
	public:
		PmergeMe();
		PmergeMe(const char **arg);
		PmergeMe(PmergeMe const & cp);
		PmergeMe &operator=(PmergeMe const & ob);
		~PmergeMe();

		// std::vector<unsigned int> getVector() const;
		// std::list<unsigned int> getList() const;
		// std::string getArg() const;
					/* Vector Container */
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
		void	insert_to_mainCHV();

					/* List Container */
		void	merge_insert_list();
		void	create_lists();
		void	printBaseList();
		void	print_lists();
		void	sort_lists();
		// void	copy_inBase_L(_list_of_lists _lists);

};


#endif