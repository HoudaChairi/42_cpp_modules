/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:06:59 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/08 13:10:44 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		static std::map<std::string, std::string> _map;
	public:
		BitcoinExchange();
		BitcoinExchange(const  BitcoinExchange& cp);
		BitcoinExchange& operator=( BitcoinExchange const & ob);
		~BitcoinExchange();

        static void parsing(std::ifstream& inFile, std::string& line);
		static void check_syntax(std::string &line);
		static int check_value(double& value, std::string& line, char *ptr, size_t &pos);
		static void store_inMap(std::ifstream &dataBase);
		static int bad_input(std::string& line,  size_t &pos, char *ptr);
		static int bad_value(double value);
		static void calcul(std::string &date, double value);
};

#endif