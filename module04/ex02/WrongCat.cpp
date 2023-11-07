/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:46:22 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 10:20:33 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat: default constructor called " << std::endl; 
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat: destructor called " << std::endl; 
}

WrongCat::WrongCat(std::string _type) : WrongAnimal(_type)
{
    type = _type;
    std::cout << "WrongCat: constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& copy)
{
    type = copy.type;
    std::cout << "WrongCat: copy constructer called " << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "WrongCat: copy assignment operator called " << std::endl;
    return (*this);        
}

void WrongCat::makeSound()const
{
    std::cout << "WrongCat: Meaw!" << std::endl;
}