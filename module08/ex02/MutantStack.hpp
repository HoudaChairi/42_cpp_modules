/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:42:33 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/03 11:55:03 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
    public: 
        MutantStack() {}
        MutantStack(const MutantStack& cp) {*this = cp;}
        MutantStack& operator=(const MutantStack& ob) {(void)ob; return (*this);}
        ~MutantStack() {}

        typedef typename std::stack<T, container>::container_type::iterator                 iterator;
        typedef typename std::stack<T, container>::container_type::const_iterator           const_iterator;
        typedef typename std::stack<T, container>::container_type::reverse_iterator         reverse_iterator;
        typedef typename std::stack<T, container>::container_type::const_reverse_iterator   const_reverse_iterator;
        
        iterator begin() {return this->c.begin();}
        iterator end(){return this->c.end();}

        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}

        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}

        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
};

#endif
