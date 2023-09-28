/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:26:08 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/27 20:17:49 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL)
{
    this->name = name;
}

HumanB::~HumanB() {}

void    HumanB::attack()
{
    std::cout << name;
    if (weapon)
        std::cout << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& WeaponPara)
{
    weapon = &WeaponPara;
}