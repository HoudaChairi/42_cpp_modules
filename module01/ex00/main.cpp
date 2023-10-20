/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:40:17 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/20 15:23:46 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie("test");
    zombie.announce();
    
    Zombie *ptr = newZombie("new");
    ptr->announce();
    
    randomChump("check");
    delete ptr, ptr = NULL;
}