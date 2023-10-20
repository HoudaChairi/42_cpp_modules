/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:34:54 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 18:45:55 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nbit = 8;

Fixed::Fixed() 
{
    std::cout << "Default constructor called " << std::endl;
    this->fixedP = 0;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called " << std::endl;
    operator=(obj);
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &obj)
        fixedP = obj.getRawBits();
    return (*this);
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called " << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (fixedP);   
}

void Fixed::setRawBits(int const raw)
{
    fixedP = raw;
}
// constructer  converts the integer to fixed-point
// all you need to do is left-shift the integer by the number of fractional bits:
// Multiply the integer by 2^8 (which is equivalent to shifting left by 8 bits)
Fixed::Fixed(const int intNum)
{
    std::cout << "Int constructor called " << std::endl;
    fixedP = intNum << nbit;
}
// constructer converts the floating-point number to fixed-point
Fixed::Fixed(const float floatNum)
{
    std::cout << "Float constructor called " << std::endl;
    fixedP = roundf(floatNum * (1 << nbit));
}

float Fixed::toFloat(void) const 
{
    return ((float)fixedP / (1 << nbit));
}

int Fixed::toInt(void) const 
{
    return (fixedP >> nbit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}