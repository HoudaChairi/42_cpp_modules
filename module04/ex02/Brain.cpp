/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:47:13 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 15:11:07 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
    for (int i = 0; i < 100; i++)
        ideas[i] = "Default idea";
    std::cout << "Brain: default constructor called " << std::endl;
}

Brain::Brain(const Brain& copy)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = copy.ideas[i];
    std::cout << "Brain: copy constructer called " << std::endl;
}
Brain& Brain::operator=(const Brain& obj)
{
    if (this != &obj)
        for (int i = 0; i < 100; i++)
            ideas[i] = obj.ideas[i];
    std::cout << "Brain: copy assignment operator called " << std::endl;
    return (*this);
}

Brain::~Brain() 
{
    std::cout << "Brain: destructor called " << std::endl;
}
