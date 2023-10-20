/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:14:54 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 18:25:12 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nbit = 8;

Fixed::Fixed() : fixedP(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int intNum)
{
    fixedP = intNum << nbit;
}

Fixed::Fixed(const float floatNum)
{
    fixedP = roundf(floatNum * (1 << nbit));
}

Fixed::Fixed(const Fixed& obj)
{
    operator=(obj);
}

Fixed& Fixed::operator=( const Fixed& obj)
{
    if (this != &obj)
        fixedP = obj.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw)
{
    fixedP = raw;
}

int Fixed::getRawBits(void) const
{
    return (fixedP);
}

int Fixed::toInt(void) const
{
    return (fixedP >> nbit);
}

float Fixed::toFloat(void) const 
{
    return ((float)fixedP / (1 << nbit));
}

std::ostream& operator<<(std::ostream & os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
//---------------------------------------------------
// The 6 comparison operators: >, <, >=, <=, == and !=.

int Fixed::operator>(const Fixed& obj) const
{
    return (fixedP > obj.fixedP);
}

int Fixed::operator<(const Fixed& obj) const
{
    return (fixedP < obj.fixedP);
}

int Fixed::operator<=(const Fixed& obj) const
{
    return (fixedP <= obj.fixedP);
}

int Fixed::operator>=(const Fixed& obj) const
{
    return (fixedP >= obj.fixedP);
}

int Fixed::operator==(const Fixed& obj) const
{
    return (fixedP == obj.fixedP);
}

int Fixed::operator!=(const Fixed& obj) const
{
    return (fixedP != obj.fixedP);
}
//-----------------------------------------------
// • The 4 arithmetic operators: +, -, *, and /

Fixed Fixed::operator+(const Fixed& obj) const
{
    return (Fixed(toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed& obj)const
{
    return (Fixed(toFloat() - obj.toFloat()));   
}

Fixed Fixed::operator*(const Fixed& obj)const
{
    return (Fixed(toFloat() * obj.toFloat()));   
}

Fixed Fixed::operator/(const Fixed& obj)const
{
    return (Fixed(toFloat() / obj.toFloat()));   
}

//-----------------------------------------------
Fixed Fixed::operator++() // pre_incre
{
    fixedP++;
    return (*this);
}

Fixed Fixed::operator--() // pre_decre
{
    fixedP--;
    return (*this);
}

Fixed Fixed::operator++(int) // post-incrementation 
{
    Fixed tmp;
    tmp = *this;
    fixedP++;
    return (tmp);
}

Fixed Fixed::operator--(int) // post-decre
{
    Fixed tmp;
    tmp = *this;
    fixedP--;
    return (tmp);
}
//-----------------------------------------------
Fixed& Fixed::min(Fixed& firstRef, Fixed& secondRef)
{
    if (firstRef < secondRef)
        return (firstRef);
    return (secondRef);
}
const Fixed& Fixed::min(const Fixed& firstRef, const Fixed& secondRef)
{
    if (firstRef < secondRef)
        return (firstRef);
    return (secondRef);
}

Fixed& Fixed::max(Fixed& firstRef, Fixed& secondRef)
{
    if (firstRef > secondRef)
        return (firstRef);
    return (secondRef);
}

const Fixed& Fixed::max(const Fixed& firstRef, const Fixed& secondRef)
{
    if (firstRef > secondRef)
        return (firstRef);
    return (secondRef);
}