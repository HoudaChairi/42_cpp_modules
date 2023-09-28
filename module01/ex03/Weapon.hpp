/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:04:37 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/25 20:19:37 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPOM_HPP
#define WEAPOM_HPP

#include "iostream"
#include "string"

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        ~Weapon();
        void setType(std::string typeV);
        const std::string& getType() const;
} ;

#endif