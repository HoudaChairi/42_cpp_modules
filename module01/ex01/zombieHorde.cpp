/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:06:18 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/14 16:09:21 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    // Allocate an array of N Zombie objects
    Zombie  *arr = new Zombie[N];
    // Initialize each Zombie object in the array with the given name
    for (int i = 0; i < N; i++)
    {
        arr[i].setName(name);
    }
    arr->setName(name); // si on fait ca , one print name specifier et les autre prends defauls name, pour cela on fait boucle // supprimer
    return (arr); //The function returns a pointer to the first zombie
}