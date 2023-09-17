/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:30:20 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/17 15:17:32 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numCont(0) {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::add(Contact& newCont)
{
    if (numCont < 8)
        array[numCont++] = newCont;
    else
    {
        for (int i = 0; i < 7; i++)
            array[i] = array[i + 1];
        array[7] = newCont;
    }
}

std::string    checkInfo(std::string str)
{
    std::string tmp;
    int x;
    
    x = str.length();
    if (x < 10)
        return (str);
    else
    {
        for (int i = 0; i < 9; i++)
            tmp += str[i];
        tmp += '.';
    }
    return (tmp);
}


void    PhoneBook::showContacts()
{
    int i = -1;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    while (++i < numCont)
    {
        std::cout << std::setw(10) << i + 1;
        std::cout << "|" << std::setw(10) << checkInfo(array[i].getFirstName());
        std::cout << "|" << std::setw(10) << checkInfo(array[i].getLastName());
        std::cout << "|" << std::setw(10) << checkInfo(array[i].getNickname()) << std::endl;
    }
}

void    PhoneBook::search()
{
    if (!numCont)
    {
        std::cout << "Your PhoneBook is empty" << std::endl;
        return ;
    }
    showContacts();
    std::string input;
    std::cout << "Enter a Number between 1 and 8:" << std::endl;
    std::getline(std::cin, input);
    
    int index = std::atoi(input.c_str());
    if (index >= 1 && index <= numCont)
    {
        std::cout << "FirstName: " << array[index - 1].getFirstName() << std::endl;
        std::cout << "LastName: " << array[index - 1].getLastName() << std::endl;
        std::cout << "Nickname: " << array[index - 1].getNickname() << std::endl;
        std::cout << "PhoneNumber: " << array[index - 1].getPhoneNumber() << std::endl;
        std::cout << "DarkSecret: " << array[index - 1].getDarkSecret() << std::endl;
    }
    else
        std::cout << "Contact index invalid!" << std::endl;
}
