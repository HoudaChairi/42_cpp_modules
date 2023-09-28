/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:06:48 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/25 20:22:14 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon&     _weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon& WeaponPara);
        ~HumanA();
        void    attack();
} ;

#endif