/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:06:28 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/11 22:31:53 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkSecret;
    public:
        Contact();
        Contact(std::string f, std::string l, std::string n, std::string p, std::string d);
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
};

typedef struct s_info
{
    std::string fName;
    std::string lName;
    std::string nName;
    std::string pNumber;
    std::string dSecret;
}   t_info;

void    contactInfo(Contact& info);
int isAlpha(std::string s);

#endif