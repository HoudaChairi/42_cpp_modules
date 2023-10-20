/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:55:23 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 18:50:11 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedP;
        static const int nbit;
    public:
        Fixed();
        Fixed(const int intNum);
        Fixed(const float floatNum);
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        int operator>(const Fixed& obj) const;
        int operator<(const Fixed& obj) const;
        int operator<=(const Fixed& obj) const;
        int operator>=(const Fixed& obj) const;
        int operator==(const Fixed& obj) const;
        int operator!=(const Fixed& obj) const;
        
        Fixed operator+(const Fixed& obj) const; 
        Fixed operator-(const Fixed& obj) const;
        Fixed operator*(const Fixed& obj)const;
        Fixed operator/(const Fixed& obj)const;

        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& min(Fixed& firstRef, Fixed& secondRef);
        static const Fixed& min(const Fixed& firstRef, const Fixed& secondRef);
        static Fixed& max(Fixed& firstRef, Fixed& secondRef);
        static const Fixed& max(const Fixed& firstRef, const Fixed& secondRef);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
