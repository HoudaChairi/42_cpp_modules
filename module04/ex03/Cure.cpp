/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:46:27 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/06 19:25:22 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& copy) : AMateria(copy.type)
{
    this->type = copy.type;
}
Cure& Cure::operator=(const Cure& obj) 
{
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

AMateria* Cure::clone() const
{
   return (new Cure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}