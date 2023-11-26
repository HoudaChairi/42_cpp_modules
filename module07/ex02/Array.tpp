/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:04:28 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/26 16:39:40 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template <typename T>
Array<T>::Array() : arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        this->arr[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T>& cp)
{
    this->_size = cp._size;
    this->arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++) 
        this->arr[i] = cp.arr[i];
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& ob)
{
    if (this != &ob)
    {
        delete this->arr;
        this->_size = ob._size;
        this->arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++) 
            this->arr[i] = ob.arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() 
{
    delete[] arr;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
template <typename T>
unsigned int Array<T>::size() const
{
    return (_size); 
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if ((unsigned int)index >= _size || index < 0)
        throw std::runtime_error("Index out of range");
    return (arr[index]);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T> &ob)
{
    for (unsigned int i = 0; i < ob.size(); i++)
        os << ob[i] << std::endl;
    return (os);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//