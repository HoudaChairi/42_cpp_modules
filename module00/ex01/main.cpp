/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:35:17 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/07 15:00:58 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int check(std::string input)
{
    if (input.length() == 0)
        std::cout << "La chaîne est vide." << std::endl;
    return (0);
}

void    ContactInfo(Contact info, std::string input)
{
    std::cout << "Can you please enter your First Name!" << std::endl;
    std::getline(std::cin, input);
    info.setFirstName(input);
    // std::cout << "First Name input: " << input << std::endl;
    std::cout << "First Name : " << info.getFirstName() << std::endl;
    std::cout << "Can you please enter your Last Name!" << std::endl;
    std::getline(std::cin, input);
    info.setLastName(input);
    info.getLastName();
    
    std::cout << "Can you please enter your Nickname!" << std::endl;
    std::getline(std::cin, input);
    info.setNickname(input);

    std::cout << "Can you please enter your PhoneNumber!" << std::endl;
    std::getline(std::cin, input);
    info.setPhoneNumber(input);
    
    std::cout << "Can you please enter your DarkSecret!" << std::endl;
    std::getline(std::cin, input);
    info.setDarkSecret(input);
    for (int i = 0; i < 5; ++i)
                std::cout << "info " << input << std::endl;
}

int main()
{
    Contact info;
    std::string input;

    std::cout << "Welcome!" << std::endl;
    std::cout << "enter one of three commands : ADD, SEARCH and EXIT." << std::endl;
   
    std::getline(std::cin, input);
    while (input != "EXIT")
    {
        if (input == "ADD")
        {
            ContactInfo(info, input); // harf lwel en majus ?
            break;
        }
        // else if (input == "SEARCH")
        //     std::cout << "SEARCH UN CONTACT" << std::endl;
    }
    return (0);
}
