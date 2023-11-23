/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_type.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 12:17:27 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    print_char(double x)
{
    if ((x >= 0 && x <= 31 ) || x == 127)
        std::cout << "char: Non displayable" << std::endl;
    else if (x < 0 || x > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: \'" << static_cast<char>(x) << "\'" << std::endl;
}

int cas_impossible(const std::string& s)
{
    if (std::strtod(s.c_str(), NULL) > INT_MAX 
    || std::strtod(s.c_str(), NULL) < INT_MIN)
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return (1);
    }
    return (0);
}
int    to_char(const std::string& s)
{
    char c = s[0];
    if (c >= '0' && c <= '9')
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(c) - 48 << std::endl;
        std::cout << "float: " << static_cast<float>(c) - 48 << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) - 48 << ".0" << std::endl;
    }
    else
    {
        std::cout << "char: \'" << c << "\'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    return (0);
}

void to_int(const std::string& s)
{
    int x = std::strtod(s.c_str(), NULL);
    print_char(x);
    if (!cas_impossible(s))
    {
        std::cout << "int: " << x << std::endl;
        std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
    }
}

void to_float(const std::string& s)
{
   float f = std::strtod(s.c_str(), NULL);
   double d = static_cast<double>(f);
   print_char(f);
   if (!cas_impossible(s))
   {
       std::cout << "int: " << static_cast<int>(f) << std::endl;
       if (f - static_cast<int>(f) == 0)
           std::cout << "float: " << f << ".0f" << std::endl;
       else
           std::cout << std::fixed << std::setprecision(2) << "float: " << f << "f" << std::endl;

       if (d - static_cast<int>(d) == 0)
           std::cout << "double: " << d << ".0" << std::endl;
       else
           std::cout << std::fixed << std::setprecision(2) << "double: " << d << std::endl;
   }
}

void to_double(const std::string& s)
{
   double d = std::strtod(s.c_str(), NULL);
   float f = static_cast<float>(d);
   print_char(d);
   if (!cas_impossible(s))
   {
       std::cout << "int: " << static_cast<int>(d) << std::endl;
       
       if (f - static_cast<int>(f) == 0) 
           std::cout <<  "float: " << f << ".0f" << std::endl;
       else
           std::cout << std::fixed << std::setprecision(2) << "float: " << f << "f" << std::endl;

       if (d - static_cast<int>(d) == 0) 
           std::cout <<  "double: " << d << ".0" << std::endl;
       else
           std::cout << std::fixed << std::setprecision(2) << "double: " << d << std::endl;
   }
}


void _literals(const std::string& s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (s == "inf" || s == "+inf" || s == "+inff" || s == "inff")
    {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (s == "-inf" || s == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl; 
    }
    else
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}
