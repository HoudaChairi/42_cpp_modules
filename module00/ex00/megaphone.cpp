/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:01:10 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/05 20:55:20 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype> // Pour toupper

// using namespace std;

int main(int argc, char **argv) 
{
    if (argc > 1)
    {
        std::string s;
        for (int i = 1; argv[i]; i++)
        {
            s = argv[i];
            for (size_t j = 0; j < s.length(); j++)
            {
                char c = std::toupper(s[j]);  
                std::cout << c;
            }  
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
