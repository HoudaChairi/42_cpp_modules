/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:06:28 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/07 11:00:16 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string FirstName; // wach n9dar nktb maju
        std::string lastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkSecret;
    public:
        void        setFirstName(std::string value);
        void        setLastName(std::string value);
        void        setNickname(std::string value);
        void        setPhoneNumber(std::string value);
        void        setDarkSecret(std::string value);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkSecret();
}   ;


#endif