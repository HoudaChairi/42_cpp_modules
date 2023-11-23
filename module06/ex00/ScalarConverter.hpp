/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:16:10 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 12:49:10 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

enum check
{
    t_char,
    t_int,
    t_float,
    t_double,
    t_literals,
};

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& cp);
        ScalarConverter& operator=(const ScalarConverter& ob);
        
        static void convert(const std::string& s);
};

int check_type(const std::string& str);
int is_Int(const std::string& str);
int is_Char(const std::string& str);
int is_Float(const std::string& str);
int is_Double(const std::string& str);
int is_literal(const std::string& s);

int  to_char(const std::string& s);
void to_int(const std::string& s);
void to_float(const std::string& s);
void to_double(const std::string& s);
void _literals(const std::string& s);

#endif