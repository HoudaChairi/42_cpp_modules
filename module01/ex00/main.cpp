/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:40:17 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/27 17:02:40 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie("test");
    zombie.announce();
    
    Zombie *ptr = zombie.newZombie("new");
    ptr->announce();
    
    zombie.randomChump("check");
    delete ptr, ptr = NULL;
}