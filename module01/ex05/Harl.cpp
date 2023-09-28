/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:41:29 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/27 12:45:05 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << " love having ... I really do !" << std::endl;
}

void Harl::info(void)
{
    std::cout << "cannot believe ... for more !" << std::endl;
}
void Harl::warning(void)
{
    std::cout << " think I deserve ... last month" << std::endl; 
}

void Harl::Harl::error(void)
{
 std::cout << "This is unacceptable ... now." << std::endl;
}
void Harl::complain(std::string level)
{
    void    (Harl::*debugPtr)() = &Harl::debug;
    void    (Harl::*infoPtr)() = &Harl::info;
    void    (Harl::*warningPtr)() = &Harl::warning;
    void    (Harl::*errorPtr)() = &Harl::error;

    std::string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*ptrLevels[4])() = {debugPtr, infoPtr, warningPtr, errorPtr};

    for (int i = 0; i < 4; i++)
        if (level == levels[i])
        {
            (this->*ptrLevels[i])();
            break ;
        }
}