/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:09 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/06 17:58:36 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ------------------------------- CONSTRUCTOR -------------------------------- */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cp) {*this = cp;}

/* -------------------------------- DESTRUCTOR -------------------------------- */

BitcoinExchange::~BitcoinExchange() {}

/* --------------------------------- OVERLOAD --------------------------------- */

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ob)
{
	if (this != &ob)
		return *this;
	return *this;
}

/* --------------------------------- METHODS ---------------------------------- */

void BitcoinExchange::check_value(double& value, std::string& line, char *ptr, size_t &pos)
{
	if (!(line[pos + 1] == ' ' 
		&& (std::isdigit(line[pos + 2]) || line[pos + 2] == '+' || line[pos + 2] == '-')))
        std::cout << "Error: bad input => " << line << std::endl;
    else if (*ptr != '\0' || line[line.length() - 1] == '.' || line[line.length() - 1] == 32)
        std::cout << "Error: bad input => " << line << std::endl;
	if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (!(value >= 0 && value <= 1000))
		std::cout << "Error: too large a number." << std::endl;
}

void BitcoinExchange::check_syntax(std::string &line)
{
    char *ptr;
    struct tm tm;
	double value;
	
    size_t pos = line.find("|", 0);
    std::string date = line.substr(0, pos);
    value = strtod(line.c_str() + pos + 2, &ptr);
    if (pos == std::string::npos/* no pipe*/|| date.length() != 11 
        || (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) || (tm.tm_year + 1900 < 2009)
		|| !(tm.tm_mon == 2 || tm.tm_mday <= 29))
        std::cout << "Error: bad input => " << line << std::endl;		
    else 
		check_value(value, line, ptr, pos);
}

void BitcoinExchange::parsing(std::ifstream& inFile, std::string& line)
{
    if (std::getline(inFile, line) && (line != "date | value"))
        throw std::runtime_error("Invalid Syntax!");
    while (!inFile.eof())
    {
		std::getline(inFile, line);
        check_syntax(line);
    }
}

/* ************************************************************************** */