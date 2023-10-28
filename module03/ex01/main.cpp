/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:18:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/25 10:35:50 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::string name = "Alice";
    std::string _name = "Charlie";
    ScavTrap scav(name);

    ClapTrap clap(_name);

    scav.attack("clap");
    scav.beRepaired(2);
    scav.takeDamage(20);
    scav.attack("clap");
    
    scav.guardGate();
    
    clap.attack("scav");
    clap.beRepaired(30);
    clap.takeDamage(30);
    clap.attack("scav");

    // ClapTrap *base = new ScavTrap("test");
    // base->attack("target");
    // delete base;
}
