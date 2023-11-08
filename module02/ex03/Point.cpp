/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:21:48 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 18:41:55 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// default constructer
Point::Point() : x(0), y(0) {} 

// constructer
Point::Point(const float nbrX, const float nbrY) : x(nbrX), y(nbrY) {} 

// copy constructor
Point::Point(const Point& copy) 
{
    operator=(copy);
}

// copy assignment operator overload
Point& Point::operator=(const Point& obj)
{
    if (this != &obj)
    {
        (Fixed&)x = obj.getX();
        (Fixed&)y = obj.getY();
    }
    return (*this);
}

// destructer
Point::~Point() {}

//get x and y
Fixed& Point::getX() const
{
    return ((Fixed&)x);
}

Fixed& Point::getY() const
{
    return ((Fixed&)y);
}
