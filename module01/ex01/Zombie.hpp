/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:06:31 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/14 14:09:02 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "string"
#include "iostream"

class Zombie
{
    private:
       std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        // ~Zombie();
        void setName(std::string newN);
        void announce(void);
        
};

Zombie* zombieHorde(int N, std::string name);
#endif