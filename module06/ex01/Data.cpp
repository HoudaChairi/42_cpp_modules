/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:33:25 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/22 12:14:21 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("Default_data") {}

Data::Data(const std::string& name) : _name(name) {}
 
Data::Data(const Data& cp) : _name(cp._name) {}

Data& Data::operator=(const Data& ob) 
{
    if (this != &ob)
        _name = ob._name;
    return (*this);
}

Data::~Data() {}

std::string Data::getName(void)
{
    return (_name);
}