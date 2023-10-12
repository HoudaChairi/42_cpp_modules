/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:09:30 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/11 19:14:47 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Calculate the area of the given triangle:
// A = [Ax(By – Cy) + Bx(Cy – Ay) + Cx(Ay - By)]/2

float area(Point const a, Point const b, Point const c)
{
    return (((a._x * (b._y - c._y)) + (b._x * (c._y - a._y)) + (c._x * (a._y - b._y))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float ABC = area(a, b, c);
    float APC = area(a, point, c);
    float APB = area(a, point, b);
    float CPB = area(c, point, b);
    if (abs(APC) == 0 || abs(APB) == 0 || abs(CPB) == 0)
        return (0);
    return (abs(ABC) == abs(APC) + abs(APB) + abs(CPB));
}