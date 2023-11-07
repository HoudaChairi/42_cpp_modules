/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:25:39 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 10:19:59 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog: default constructor called " << std::endl; 
}

Dog::~Dog()
{
    std::cout << "Dog: destructor called " << std::endl; 
    delete brain;
}

Dog::Dog(const Dog& copy) : AAnimal(copy)
{
    this->brain = new Brain(*copy.brain);
    this->type = copy.type;
    std::cout << "Dog: copy constructer called " << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        delete brain;
        this->brain = new Brain(*obj.brain);
        type = obj.type;
    }
    std::cout << "Dog: copy assignment operator called " << std::endl;
    return (*this);
}

void Dog::makeSound()const
{
    std::cout << "Dog: Woof!" << std::endl;
}