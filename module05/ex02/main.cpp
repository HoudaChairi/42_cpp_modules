/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:37:25 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 11:33:26 by hchairi          ###   ########.fr       */
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
        Bureaucrat b("sokrate", 2);
        ShrubberyCreationForm s("Shrubbery");
        RobotomyRequestForm r("Robotomy");
        PresidentialPardonForm p("President");
        
        // b.signForm(s);
        b.executeForm(s);
        b.signForm(r);
        b.executeForm(r);
        b.signForm(p);
        b.executeForm(p);
        std::cout << b;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    } 
}
