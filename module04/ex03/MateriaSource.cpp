/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:33:26 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/07 15:44:22 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        if (_materia[i])
            delete _materia[i];
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    for(int i = 0; i < 4; i++)
        _materia[i] = copy._materia[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    if (this != & obj)
    {
        for(int i = 0; i < 4; i++)
            _materia[i] = obj._materia[i];
    }
    return(*this);
}


void MateriaSource::learnMateria(AMateria* materia)
{  
    if (materia)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i] == NULL)
            {
                _materia[i] = materia;
                break ;
            }
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return (_materia[i]->clone());
    }
    return (NULL);
}