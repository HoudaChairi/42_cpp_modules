/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:03:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/08 18:59:34 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, __unused char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN 'list of numbers'" << std::endl; 
        return (1);
    }
    try
    {
        std::string format = av[1];
        RPN rpn(format);
        std::cout << rpn.getResult() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return (0);
}