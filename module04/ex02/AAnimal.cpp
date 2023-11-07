/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:22:04 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 10:19:27 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "AAnimal";
    std::cout << "AAnimal: default constructor called " << std::endl; 
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal: destructor called " << std::endl; 
}

AAnimal::AAnimal(const AAnimal& copy)
{
    type = copy.type;
    std::cout << "AAnimal: copy constructer called " << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "AAnimal: copy assignment operator called " << std::endl;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (type);
}