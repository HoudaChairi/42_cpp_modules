/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:18:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/15 19:40:04 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    std::string name = "mel-moun";
    std::string _name = "hchairi";
    
    FragTrap frag(name);   
    ClapTrap clap(_name);
    
    frag.attack("Frag");
    clap.attack("clap");
    frag.highFivesGuys();
    frag.beRepaired(3);
    frag.takeDamage(15);
    
    clap.beRepaired(3);
    clap.takeDamage(1);
}