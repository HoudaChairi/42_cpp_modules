/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:05:51 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/27 11:35:38 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* tab = zombieHorde(5, "zombie");
    for (int i = 0; i < 5; i++)
        tab[i].announce();
    delete[] tab, tab = NULL;
    return (0);
}