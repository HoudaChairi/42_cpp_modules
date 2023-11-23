/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:23:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 12:01:46 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int is_literal(const std::string& s)
{
    std::string arr[12] = {"-inff", "+inff", "inff"
        , "+nanf", "-nanf","nanf"
        , "-inf", "+inf", "inf"
        , "+nan", "-nan", "nan"};
    for(int i = 0; i < 12; i++)
    {
        if (s == arr[i])
            return (0);       
    }
    return (1);
}

int is_Char(const std::string& str)
{
    if (str.length() == 1)
        return (0);
    return (1);
}


int is_Int(const std::string& str)
{
    size_t i = 0;
    if(str[0] == '+' || str[0] == '-')
        i++;
    for(; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return (1);
    }
    if (str[i] == '\0')
        return (0);
    return (1);
}
int is_Float(const std::string& str)
{
    size_t i = 0;
    int countP = 0;
    int countF = 0;

    if(str[0] == '+' || str[0] == '-')
        i++;
    for(; i < str.length() && (isdigit(str[i]) || str[i] == 'f' || str[i] == '.'); i++)
    {
        if (str[i] == '.')
        {
            if (!std::isdigit(str[i + 1]))   
                return (1);
            countP++;
        }
        if (str[i] == 'f')
            countF++;
    }
    if (countP == 1 && countF == 1 && str[i - 1] == 'f' && str[i] == '\0')
        return (0);
    return (1);
}

int is_Double(const std::string& str)
{
    size_t i = 0;
    int countP = 0;
    
    if(str[0] == '+' || str[0] == '-')
        i++;
    for(; i < str.length() && (isdigit(str[i]) || str[i] == '.'); i++)
    {
        if (str[i] == '.')        
            countP++;
    }
    if (countP == 1 && str[i - 1] != '.' && str[i] == '\0')
        return (0);
    return (1);
}

int check_type(const std::string& str)
{
    if (!is_literal(str))
        return t_literals;
    else if (!is_Char(str))
        return t_char;
    else if (!is_Int(str))
        return t_int;
    else if (!is_Float(str))
        return t_float;
    else if (!is_Double(str))
        return t_double;
    return (1337);
}
