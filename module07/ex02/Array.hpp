/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:03:38 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/26 15:58:44 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T         *arr;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& cp);
        Array& operator=(const Array& ob);
        ~Array();

        T& operator[](int index);
        unsigned int size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T> &ob);

#include "Array.tpp"

#endif