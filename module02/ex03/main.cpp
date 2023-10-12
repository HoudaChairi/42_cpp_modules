/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:35:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/11 19:14:08 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
   Point a(4, 2);
   Point b(4.0, 6.0);
   Point c(10.0, 4.0);
   Point p(4,4);

   if (bsp(a, b, c, p))
      std::cout << "Point is inside the triangle" << std::endl;
   else
      std::cout << "Point is outside the triangle" << std::endl;
}
