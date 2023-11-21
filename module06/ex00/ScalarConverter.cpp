/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:16:08 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/21 15:17:44 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cp)
{
    *this = cp;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ob)
{
    if (this != &ob)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& s)
{
    switch (check_type(s))
    {
        case t_char:
            to_char(s);
            break;
        case t_int:
            to_int(s);
            break;
        case t_float:
            to_float(s);
            break;
        case t_double:
            to_double(s);
            break;
        case t_literals:
            _literals(s);
            break;
        default:
        {
            std::cout << " Unknown type " << std::endl;
            break;   
        }
    }
}