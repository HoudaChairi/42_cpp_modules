/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:40:22 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/08 13:18:27 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, std::string> BitcoinExchange::_map;

int main(int ac, char **av)
{
    std::ifstream inFile(av[1]);
    std::ifstream dataBase("data.csv");
    if (ac != 2 || !inFile.is_open() || !dataBase.is_open())
        std::cout << "Error: could not open file." << std::endl;
    else
    {
        std::string line;
        try {
            BitcoinExchange::store_inMap(dataBase);
            BitcoinExchange::parsing(inFile,line);
        } 
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        inFile.close();
    }
    return (0);
}
