/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:15:47 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/10 13:41:35 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>

typedef std::vector<unsigned int> _ui_vector;

class PmergeMe
{
	private:
		_ui_vector	_vector;
		std::vector<_ui_vector>	_vectofV;
		// std::list<list<unsigned int> >		_list;
		// std::list<unsigned int>		_list;
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
		std::vector<_ui_vector> getVectofV() const ;
		size_t	getNumber(const char *number);
		bool	isNumber(const char *number);
		void	merge_recursive();
		void	create_vectors();
		void	print_vectors();
		void	sort_vectors();
		void	swap_vectors(size_t i);
		void	copy_inBase_V();
		void	printBaseVector(); // remove or modifier
		void	check_paires();

};


#endif