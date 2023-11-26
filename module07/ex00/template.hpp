/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:55:25 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/26 15:06:11 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename T>
void swap(T& arg1, T& arg2)
{
    T tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
}
template <typename T>
T min(T firstArg, T secondArg)
{
    if (firstArg < secondArg)
        return (firstArg);
    else
        return (secondArg);
}
template <typename T>
T max(T firstArg, T secondArg)
{
    if (firstArg > secondArg)
        return (firstArg);
    else
        return (secondArg);
}  
 
#endif