/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:03:30 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/26 16:40:42 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array<int>ob(2);
        ob[0] = 13;
        ob[1] = 37;
        std::cout << ob;

        Array<std::string>ob1(1);
        ob1[0] = "Houda Chairi";
        std::cout << ob1;

        Array<double>ob2(3); 
        ob2[0] = 19.2;
        ob2[1] = 10.4;
        //out of range:
        ob2[-1] = 42.42; 
        ob2[4] = 27.5;
        std::cout << ob2;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}
