/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:25:35 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/24 19:45:09 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat: default constructor called " << std::endl; 
}

// Cat::Cat(std::string _type) : Animal(_type)
// {
//     type = _type;
//     brain = new Brain(); ////////
//     std::cout << "Cat: constructor called" << std::endl;
// }

Cat::Cat(std::string _type) : Animal(_type)
{
    type = _type;
    brain = new Brain(); ////////
    std::cout << "Cat: constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat: destructor called " << std::endl;
    delete brain; //////// 
}
//copy constructer 
Cat::Cat(const Cat& copy)
{
    type = copy.type;
    // ftech kifach deep copy 
    std::cout << "Cat: copy constructer called " << std::endl;
}

// assignement operator
Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "Cat: copy assignment operator called " << std::endl;
    return (*this);
}

void Cat::makeSound()const
{
    std::cout << "Cat: sound ..." << std::endl;
}