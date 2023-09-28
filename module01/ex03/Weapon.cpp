/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:06:16 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/26 15:14:34 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string typeV)
{
    this->type = typeV;
}

Weapon::~Weapon() {}

void Weapon::setType(std::string typeV)
{
    type = typeV;
}

const std::string& Weapon::getType() const
{
    return type;
}
