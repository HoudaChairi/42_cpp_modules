/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:36:16 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/20 15:27:00 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Losers.hpp"

int main(int ac, char **av)
{       
    if (ac != 4)
        return (1);
    std::string line;
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream inFile(av[1]);
	std::ofstream outFile(std::strcat(av[1], ".replace"));
    if (inFile.is_open() && outFile.is_open()) 
    {
        size_t  pos;
        while (std::getline(inFile, line))
        {
            pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            outFile << line;
            if (!inFile.eof())
                outFile << "\n";
        }
        inFile.close();
        outFile.close();
    }
    else 
        return (std::cerr << "Failed to open the file." << std::endl, 1);
    return (0);
}