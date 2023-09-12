/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:21 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/11 15:59:07 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};

// ajoute default constracter 
Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string d)
{
   FirstName = f;
    LastName = l;
    Nickname = n;
    PhoneNumber = p;
    DarkSecret = d;
}

void    Contact::setFirstName(std::string value)
{
   FirstName = value;
}

void    Contact::setLastName(std::string value)
{
   LastName = value;
}

void    Contact::setNickname(std::string value)
{
   Nickname = value;
}

void    Contact::setPhoneNumber(std::string value)
{
   PhoneNumber = value;
}

void    Contact::setDarkSecret(std::string value)
{
   DarkSecret = value;
}

std::string Contact::getFirstName()
{
    return (FirstName);
}

std::string Contact::getLastName()
{
    return (LastName);
}

std::string Contact::getNickname()
{
    return (Nickname);
}

std::string Contact::getPhoneNumber()
{
    return (PhoneNumber);
}

std::string Contact::getDarkSecret()
{
    return (DarkSecret);
}