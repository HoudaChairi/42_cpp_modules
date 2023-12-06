/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:06:59 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/06 17:57:13 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const  BitcoinExchange& cp);
		BitcoinExchange& operator=( BitcoinExchange const & ob);
		~BitcoinExchange();

        static void parsing(std::ifstream& inFile, std::string& line);
		static void check_syntax(std::string &line);
		static void check_value(double& value, std::string& line, char *ptr, size_t &pos);
};

#endif