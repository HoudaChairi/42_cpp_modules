/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:10:20 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/15 17:10:38 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
    name = "default";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called " << std::endl;
}
//constructer
DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name)
{
    name = _name;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << " constructor called " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : 
ClapTrap(obj), 
ScavTrap(obj), 
FragTrap(obj)
{
    operator=(obj);
    std::cout << "DiamondTrap copy constructer called " << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    std::cout << "DiamondTrap copy assignment operator called " << std::endl;
    if (this != &obj)
    {
        name = obj.name;
        ClapTrap::operator=(obj);
    }
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}


void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " DiamondTrap" << std::endl;
    std::cout << "I am " << ClapTrap::name << " ClapTrap" << std::endl;
}