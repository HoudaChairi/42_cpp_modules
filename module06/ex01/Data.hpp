/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:30:38 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/22 10:54:08 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    private:
        std::string _name;
    public:
        Data();
        Data(const std::string& name); 
        Data(const Data& cp);
        Data& operator=(const Data& ob);
        ~Data();

        std::string getName(void);
};

#endif