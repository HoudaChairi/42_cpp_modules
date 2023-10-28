/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:21:14 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/22 20:39:21 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public: // don't forget canonical form 
        Animal();
        Animal(std::string _type);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& obj);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound()const;
};



#endif