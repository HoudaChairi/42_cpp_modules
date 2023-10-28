/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:46:22 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/23 12:30:06 by hchairi          ###   ########.fr       */
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
// copy constructer
WrongCat::WrongCat(const WrongCat& copy)
{
    type = copy.type;
    std::cout << "WrongCat: copy constructer called " << std::endl;
}
// assignement operator
WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    if (this != &obj)
        type = obj.type; // or gettype () wola hta nkunu an3aytula f main ??
    std::cout << "WrongCat: copy assignment operator called " << std::endl;
    return (*this);        
}

void WrongCat::makeSound()const
{
    std::cout << "WrongCat: sound ..." << std::endl;
}