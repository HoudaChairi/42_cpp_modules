/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:29:01 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/16 10:42:04 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//default constructer
ScavTrap::ScavTrap() : ClapTrap()
{
    name = "default Scav";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called " << std::endl;
}

//Constructer                              
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called " << std::endl;
}
//copy constructer
ScavTrap::ScavTrap(const ScavTrap& obj)
{
    std::cout << "ScavTrap copy constructer called " << std::endl;
    operator=(obj);
}
//Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "ScavTrap copy assignment operator called " << std::endl;
    if (this != &obj)
    {
        name = obj.name;
        hitPoints = obj.hitPoints;
        energyPoints = obj.energyPoints;
        attackDamage = obj.attackDamage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints >= 1 && energyPoints >= 1)
    {
        std::cout << "ScavTrap " << name << " attacks " << target;
        std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
        hitPoints--;
        energyPoints--;
        return ;
    }
    std::cout << "ScavTrap can not attack .." << std::endl;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode. " << std::endl;
}