/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:21 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/07 10:59:51 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setFirstName(std::string value)
{
   FirstName = value;
}

void    Contact::setLastName(std::string value)
{
   lastName = value;
}

void    Contact::setNickname(std::string value)
{
   lastName = value;
}

void    Contact::setPhoneNumber(std::string value)
{
   lastName = value;
}

void    Contact::setDarkSecret(std::string value)
{
   lastName = value;
}

std::string Contact::getFirstName()
{
    return (FirstName);
}

std::string Contact::getLastName()
{
    return (lastName);
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