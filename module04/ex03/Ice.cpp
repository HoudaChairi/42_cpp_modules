/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:48:15 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/06 19:39:24 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& copy) : AMateria(copy.type)
{
    this->type = copy.type;
}
Ice& Ice::operator=(const Ice& obj)
{
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

AMateria* Ice::clone() const
{
   return (new Ice);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}