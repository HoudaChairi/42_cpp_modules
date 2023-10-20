/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:52:31 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 18:15:49 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedP;
        static const int nbit;
    public:
        // Orthodox Canonical Form
        Fixed();
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        // Orthodox Canonical Form

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif