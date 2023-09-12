/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:35:17 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/11 22:41:30 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int isNumber(std::string s)
{
    int x = 0;
 
    x = s.length();
    for(int i = 0; i < x; i++)
        if (!isdigit(s[i]))
            return (0);
    return (1);
}

int isAlpha(std::string s)
{
    int x = 0;

    x = s.length();
    for(int i = 0; i < x; i++)
        if (!isalpha(s[i]))
            return (0);
    return (1);
}

void    setInfo(Contact& info, t_info& tmp)
{
    info.setFirstName(tmp.fName);
    info.setLastName(tmp.lName);
    info.setNickname(tmp.nName);
    info.setPhoneNumber(tmp.pNumber);
    info.setDarkSecret(tmp.dSecret);
}

int    fill(std::string message, std::string& s)
{
    std::cout << message << std::endl;
    std::getline(std::cin, s);
    while (!isAlpha(s) || s.empty())
    {
        if (std::cin.eof())
            return (EXIT_FAILURE);
        std::cout << message << std::endl;
        std::getline(std::cin, s);
    }
    return (EXIT_SUCCESS);
}

int    fillNum(std::string message, std::string& s)
{
    std::cout << message << std::endl;
    std::getline(std::cin, s);
    while (!isNumber(s) || s.empty())
    {
        if (std::cin.eof())
            return (EXIT_FAILURE);
        std::cout << message << std::endl;
        std::getline(std::cin, s);
    }
    return (EXIT_SUCCESS);
}

void    contactInfo(Contact& info)
{
    t_info      tmp;
    
    if (fill("Enter first name: ", tmp.fName))
        return ;
    if (fill("Enter last name: ", tmp.lName))
        return ;
    if (fill("Enter nickname: ", tmp.nName))
        return ;
    if (fillNum("Enter a number: ", tmp.pNumber))
        return ;
    if (fill("Enter darkSecret: ", tmp.dSecret))
        return ;
    setInfo(info, tmp);
} 

int main()
{
    Contact     info;
    PhoneBook   book;
    std::string input;
     
    std::cout << "Welcome!" << std::endl;
    while (input != "EXIT")
    {
        if (std::cin.eof())
            break;
        std::cout << "Enter command : ADD, SEARCH and EXIT." << std::endl;
        if (!std::getline(std::cin, input))
            break;
        else if (input == "ADD")
        {
            contactInfo(info);
            book.add(info);
        }
        else if (input == "SEARCH")
            book.search();
    }
    return (0);
}
