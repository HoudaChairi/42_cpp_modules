/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:16:41 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/16 10:42:28 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//default constructer
ClapTrap::ClapTrap() : 
name("default ClapTrap"), 
hitPoints(10), 
energyPoints(10), 
attackDamage(0) 
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

//constructer
ClapTrap::ClapTrap(std::string _name) : 
name(_name), 
hitPoints(10), 
energyPoints(10), 
attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructor called " << std::endl;
}
//copy constructer
ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "ClapTrap copy constructer called " << std::endl;
    operator=(obj);
}
//Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    std::cout << "ClapTrap copy assignment operator called " << std::endl;
    if (this != &obj)
    {
        name = obj.name;
        hitPoints = obj.hitPoints;
        energyPoints = obj.energyPoints;
        attackDamage = obj.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called " << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints >= 1 && energyPoints >= 1)
    {
        std::cout << "ClapTrap " << name << " attacks " << target;
        std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
        return ;
    }
    std::cout << "ClapTrap can not attack .." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints >= 1 && energyPoints >= 1)
    {
        std::cout << "ClapTrap " << name << " repairs ";
        std::cout << amount << " hit points. " << std::endl;
        hitPoints += amount;
        energyPoints--;
        return ;
    }
    std::cout << "ClapTrap can not repair .." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
        std::cout << "ClapTrap " << name << " is dead" << std::endl;
    else
    {
        if (amount >= hitPoints)
        {
            hitPoints = 0;
            std::cout << "ClapTrap " << name << " is dead" << std::endl;
        }
        else
        {
            hitPoints -= amount;
            std::cout << "ClapTrap " << name << " lost " << amount << " of hit points" << std::endl;
        }
    }
}