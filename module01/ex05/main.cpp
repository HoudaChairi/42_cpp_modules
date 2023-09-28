/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:40:59 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/24 11:54:34 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string level;

    std::cout << "Enter un Niveau : debug, info, warning or error" << std::endl;
    std::cin >> level;
    
    harl.complain(level);

    return (0);
}