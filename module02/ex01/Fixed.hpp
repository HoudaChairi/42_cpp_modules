/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:35:06 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 18:14:47 by hchairi          ###   ########.fr       */
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
        // Orthodox Canonical Form
        Fixed();
        Fixed(const int intNum);
        Fixed(const float floatNum);
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        // Orthodox Canonical Form

        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif