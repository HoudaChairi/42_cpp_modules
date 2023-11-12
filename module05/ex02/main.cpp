/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:37:25 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/12 16:31:02 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    
    try
    {
        Bureaucrat b("seqrat", 2);
        // ShrubberyCreationForm s("mel-moun");
        RobotomyRequestForm s("houda");
        b.signForm(s);
        b.executeForm(s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}