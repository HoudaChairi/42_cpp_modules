/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:05:51 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/14 16:06:45 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// int main()
// {
//     int N = 5;
//     std::string zombieName = "Zombot";
//     Zombie* horde = zombieHorde(N, zombieName);
//     for (int i = 0; i < N; ++i) {
//         horde[i].announce();
//     }
//     // horde->announce(); 
//     delete[] horde;
//     return 0;
// }
int main()
{
    int N;
    std::string str;
    std::cin >> N;
    std::cin >> str;
    Zombie* tab = zombieHorde(N, str);
    tab->setName(str);
    for (int i = 0; i < N; i++)
    {
        tab[i].announce();
    }
    delete[] tab, tab = NULL;
    return (0);
}