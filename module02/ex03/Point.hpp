/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:21:15 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/11 18:50:03 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

# define _x getX().toFloat()
# define _y getY().toFloat()

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        //Orthodox
        Point();
        Point(const float nbrX, const float nbrY);
        Point(const Point& copy);
        Point& operator=(const Point& obj);
        ~Point();
        //Orthodox

        Fixed& getX() const;
        Fixed& getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif

