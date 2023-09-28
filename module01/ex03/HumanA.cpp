/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:21:23 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/25 20:18:54 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& WeaponPara) : _weapon(WeaponPara)
{
    this->name = name;
}

HumanA::~HumanA() {}

void    HumanA::attack()
{
    std::cout << name;
    std::cout << " attacks with their " << this->_weapon.getType() << std::endl;
}
