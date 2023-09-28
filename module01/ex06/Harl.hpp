/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:28:21 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/24 12:58:44 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include "iostream"
#include "string"

class Harl
{
    private:
       void debug(void);
       void info(void);
       void warning(void);
       void error(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};
#endif