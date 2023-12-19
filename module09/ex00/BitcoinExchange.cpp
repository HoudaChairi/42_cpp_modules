/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:09 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/18 15:10:18 by hchairi          ###   ########.fr       */
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
		_map = ob._map;
	return *this;
}

/* --------------------------------- METHODS ---------------------------------- */

void BitcoinExchange::store_inMap(std::ifstream &dataBase)
{
    std::string lineB;
    std::getline(dataBase, lineB);
    while (!dataBase.eof())
    {
        std::getline(dataBase, lineB);
        size_t pos = lineB.find(",");
        _map.insert(std::make_pair(lineB.substr(0, pos), lineB.substr(pos + 1)));
    }
}

void BitcoinExchange::calcul(std::string &date, double value)
{
    std::map<std::string, std::string>::iterator it = _map.lower_bound(date);
    if (it->first != date)
        it--;
    double map_value = std::strtod(it->second.c_str(), NULL);
    std::cout << date << "=> " << value << " = "  << (map_value * value) << std::endl;
}

int BitcoinExchange::bad_input(std::string& line,  size_t &pos, char *ptr)
{
    if (!(line[pos + 1] == ' ' 
		&& (std::isdigit(line[pos + 2]) || line[pos + 2] == '+' || line[pos + 2] == '-')))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return (1);
    }
    else if (*ptr != '\0' || line[line.length() - 1] == '.' || line[line.length() - 1] == 32)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return (1);
    }
    return (0);
}
int BitcoinExchange::bad_value(double value)
{
    if (value < 0)
    {
		std::cout << "Error: not a positive number." << std::endl;
        return (1);
    }
	else if (!(value >= 0 && value <= 1000))
    {
		std::cout << "Error: too large a number." << std::endl;
        return (1);
    }
    return (0);
}

int BitcoinExchange::check_value(double& value, std::string& line, char *ptr, size_t &pos)
{
    if (bad_input(line, pos, ptr))
        return (1);
    if (bad_value(value))
        return (1);
    return (0);
}

void BitcoinExchange::check_syntax(std::string &line)
{
    char *ptr;
    struct tm tm;
	
    size_t pos = line.find("|", 0);
    std::string date = line.substr(0, pos);
    double value = strtod(line.c_str() + pos + 2, &ptr);
    if (pos == std::string::npos || date.length() != 11 
        || (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) || (tm.tm_year + 1900 < 2009)
		|| !(tm.tm_mon == 2 || tm.tm_mday <= 29) || (tm.tm_mday == 00))
        std::cout << "Error: bad input => " << line << std::endl;
    else if (check_value(value, line, ptr, pos))
        return ;
    else
        calcul(date, value);
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