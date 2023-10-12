/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:23:14 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/04 12:30:06 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default constructer
Fixed::Fixed() 
{
    std::cout << "Default constructor called " << std::endl;
    this->fixedP = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called " << std::endl;
    operator=(obj); //assign the values of the existing object to the newly created object.
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &obj)
        fixedP = obj.getRawBits();
    return (*this);
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called " << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called " << std::endl;
    return (fixedP);   
}

void Fixed::setRawBits(int const raw)
{
    fixedP = raw;
}
