/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:25:35 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 10:17:08 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat: default constructor called " << std::endl; 
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called " << std::endl; 
}

Cat::Cat(const Cat& copy)
{
    type = copy.type;
    std::cout << "Cat: copy constructer called " << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "Cat: copy assignment operator called " << std::endl;
    return (*this);
}

void Cat::makeSound()const
{
    std::cout << "Cat: Meaw!" << std::endl;
}