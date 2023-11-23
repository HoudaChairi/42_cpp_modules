/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:16:29 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 12:45:21 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& cp)
{
    *this = cp;
}

Serializer& Serializer::operator=(const Serializer& ob)
{
    if (this != &ob)
        return (*this);
    return (*this);
}

//~~~~casting the pointer to uintptr_t~~~~//
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

//~~casting the uintptr_t back to a pointer to Data~~//
Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}