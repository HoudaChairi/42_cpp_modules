/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:35 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/03 16:54:03 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

template <typename T>
void easyfind(T& container, int i)
{
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it == container.end())
        throw std::runtime_error("Value not found in the container.");
    std::cout << "Value " << i << " found in the container." << std::endl;
}

#endif