/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:18:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/15 19:39:43 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::string name = "mel-moun";
    std::string _name = "hchairi";
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
}
