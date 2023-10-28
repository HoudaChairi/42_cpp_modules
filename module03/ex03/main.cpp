/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:18:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/15 18:30:28 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap first = DiamondTrap("Alice");

    DiamondTrap second;
    
    second = first;

    first.attack("Bob");
    second.attack("Charlie");
    first.takeDamage(16);
    first.whoAmI();
    first.attack("Bob");

    return (0);
}