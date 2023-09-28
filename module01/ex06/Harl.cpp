/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:28:08 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/26 16:35:58 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "<< std::endl;
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do" << std::endl;
    std::cout << "\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << "\n";
}
void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. "<< std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << "\n";
}

void Harl::Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
    void    (Harl::*debugPtr)() = &Harl::debug;
    void    (Harl::*infoPtr)() = &Harl::info;
    void    (Harl::*warningPtr)() = &Harl::warning;
    void    (Harl::*errorPtr)() = &Harl::error;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptrLevels[4])() = {debugPtr, infoPtr, warningPtr, errorPtr};
    
    int i = 0;
    for (; i < 4; i++)
        if (level == levels[i])
            break;
    switch (i)
    {
        case 0:
            (this->*ptrLevels[0])();
        case 1:
            (this->*ptrLevels[1])();
        case 2:
            (this->*ptrLevels[2])();
        case 3:
            (this->*ptrLevels[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
    }  
}
