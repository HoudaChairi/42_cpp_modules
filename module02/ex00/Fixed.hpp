/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:52:31 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/04 12:14:35 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedP;
        static const int nbit = 8;
    public:
        // Orthodox Canonical Form
        Fixed(); //Default constructor
        Fixed(const Fixed& obj); // Copy constructor
        Fixed& operator=(const Fixed& obj); //Copy assignment operator
        ~Fixed(); // Destructor
        // Orthodox Canonical Form

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif