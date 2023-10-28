/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:20:50 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/16 10:44:10 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    name = "default Frag";
    hitPoints = 100;
    // energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called " << std::endl;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destructor called " << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    name = _name;
    hitPoints = 100;
    // energyPoints = 100;  
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called " << std::endl;
}
FragTrap::FragTrap(const FragTrap& obj)
{
    std::cout << "FragTrap copy constructer called " << std::endl;
    operator=(obj);
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout << "FragTrap copy assignment operator called " << std::endl;
    if (this != &obj)
    {
        name = obj.name;
        hitPoints = obj.hitPoints;
        energyPoints = obj.energyPoints;
        attackDamage = obj.attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Give me some high fives, guys!" << std::endl;
}