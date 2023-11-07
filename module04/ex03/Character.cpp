/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:31:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 12:34:21 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default")
{
    for (int i = 0; i < 4; i++)
    {
        inventaire[i] = NULL;
        unequip_Inv[i] = NULL;
    }
}

Character::Character(const std::string& _name) : name(_name)
{
    for (int i = 0; i < 4; i++)
    {
        inventaire[i] = NULL;
        unequip_Inv[i] = NULL;
    }
}

Character::Character(const Character& copy)
{
    this->name = copy.name;
    for (int i = 0; i < 4; i++)
    {
        if (copy.inventaire[i])
            this->inventaire[i] = copy.inventaire[i]->clone();
        else
            this->inventaire[i] = NULL;
        if (copy.unequip_Inv[i])
            this->unequip_Inv[i] = copy.unequip_Inv[i]->clone();
        else
            this->unequip_Inv[i] = NULL;
    }
}
Character& Character::operator=(const Character& obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        for(int i = 0; i < 4; i++)
        {
            if (inventaire[i])
                delete inventaire[i];
            if (unequip_Inv[i])
                delete unequip_Inv[i]; 
        }
        for (int i = 0; i < 4; i++)
        {
            if (obj.inventaire[i])
                this->inventaire[i] = obj.inventaire[i]->clone();
            if (obj.unequip_Inv[i])
                this->unequip_Inv[i] = obj.unequip_Inv[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventaire[i])
        {
            delete inventaire[i];
            inventaire[i] = NULL;
        }
        if (unequip_Inv[i])
        {
            delete unequip_Inv[i];
            unequip_Inv[i] = NULL;
        }
    }
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventaire[i] == NULL)
            {
                inventaire[i] = m;
                return ;
            }
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    if (inventaire[idx] != NULL)
    {
        unequip_Inv[idx] = inventaire[idx];
        inventaire[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventaire[idx] != NULL)
        inventaire[idx]->use(target);
}