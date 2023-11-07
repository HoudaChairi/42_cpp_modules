/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:22:04 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 10:18:26 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal: default constructor called " << std::endl; 
}

Animal::~Animal()
{
    std::cout << "Animal: destructor called " << std::endl; 
}

Animal::Animal(const Animal& copy)
{
    type = copy.type;
    std::cout << "Animal: copy constructer called " << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "Animal: copy assignment operator called " << std::endl;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal: sound ..." << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}