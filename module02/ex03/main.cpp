/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:35:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/19 17:38:07 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
   Point a(1, 1);
   Point b(1, 5);
   Point c(5, -3);
   Point p(2, 2);

   if (bsp(a, b, c, p))
      std::cout << "Point is inside the triangle" << std::endl;
   else
      std::cout << "Point is outside the triangle" << std::endl;
}
 