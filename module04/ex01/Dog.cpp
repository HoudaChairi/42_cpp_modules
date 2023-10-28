/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:25:39 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/24 19:33:25 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog: default constructor called " << std::endl; 
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called " << std::endl; 
    delete brain; // ???? getBrain  wach anhtajuha fmain??
}

Dog::Dog(std::string _type) : Animal(_type)
{
    type = _type;
    brain = new Brain();
    std::cout << "Dog: constructor called" << std::endl;
}

//copy constructer
Dog::Dog(const Dog& copy)
{
    type = copy.type;
    std::cout << "Dog: copy constructer called " << std::endl;
}

//assignement operator
Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
        type = obj.type;
    std::cout << "Dog: copy assignment operator called " << std::endl;
    return (*this);
}

void Dog::makeSound()const
{
    std::cout << "Dog: sound ..." << std::endl;
}