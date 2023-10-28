/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:18:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/28 11:19:25 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::string s = "clap";
    // Create a ClapTrap object using the default constructor
    ClapTrap clap;

    // Create a ClapTrap object with a specific name using the constructor
    ClapTrap clap1(s);

    //  Create a copy of clap2 using the copy constructor
   
    ClapTrap clap2(clap1); // ==  ClapTrap clap2 = clap1;

    //  Assign clap with clap2 using the assignment operator
    clap = clap2;
        
    clap.beRepaired(10);
    clap.takeDamage(5);
    clap.attack("Alice");
    return (0);
}


