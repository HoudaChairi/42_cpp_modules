/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:34:54 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/09 12:26:47 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
    std::cout << "Default constructor called " << std::endl;
    this->fixedP = 0;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called " << std::endl;
    operator=(obj); //assign the values of the existing object to the newly created object.
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
    // std::cout << "getRawBits member function called " << std::endl;
    return (fixedP);   
}

void Fixed::setRawBits(int const raw)
{
    fixedP = raw;
}
Fixed::Fixed(const int intNum)
{
    std::cout << "Int constructor called " << std::endl;
    fixedP = intNum << nbit; // Multiply the integer by 2^8 (which is equivalent to shifting left by 8 bits)
    //his converts the integer to fixed-point format with 8 bits for the fractional part
}

Fixed::Fixed(const float floatNum)
{
    // Multiply the floating-point number by 2^8 (which is equivalent to shifting left by 8 bits)
    // This converts the floating-point number to fixed-point format with 8 bits for the fractional part
    std::cout << "Float constructor called " << std::endl;
    fixedP = round(floatNum * (1 << nbit));
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
// this code allows you to print a Fixed object 
//by converting it to a float value and then outputting it to the standard output stream.