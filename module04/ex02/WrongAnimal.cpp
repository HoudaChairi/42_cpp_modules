/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:43:58 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 10:20:11 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    type = "default";
    std::cout << "WrongAnimal: default constructor called " << std::endl; 
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal: destructor called " << std::endl; 
}

WrongAnimal::WrongAnimal(std::string _type) :  type(_type) 
{
    std::cout << "WrongAnimal: constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    type = copy.type;
    std::cout << "WrongAnimal: copy constructer called " << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "WrongAnimal: copy assignment operator called " << std::endl;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal: sound ..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}