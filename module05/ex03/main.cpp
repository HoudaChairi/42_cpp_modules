/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:37:25 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 13:12:01 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() 
{
    Intern intern;
    AForm* form1= NULL;
    AForm* form2= NULL;
    AForm* form3= NULL;
    AForm* form4 = NULL;
    try
    {
        Bureaucrat ob("Sokrate", 2);
        std::cout << "~~~~~~~~~~~~~Form1~~~~~~~~~~~~~~~" << std::endl;
        form1 = intern.makeForm("shrubbery creation", "Form1");
        ob.signForm(*form1);
        ob.executeForm(*form1);
        
        std::cout << "~~~~~~~~~~~~~Form2~~~~~~~~~~~~~~~" << std::endl;
        form2 = intern.makeForm("robotomy request", "Form2");
        // ob.signForm(*form2);
        ob.executeForm(*form2);
        
        std::cout << "~~~~~~~~~~~~~Form3~~~~~~~~~~~~~~~" << std::endl;
        form3 = intern.makeForm("presidential pardon", "Form3");
        ob.signForm(*form3);
        ob.executeForm(*form3);
 
        std::cout << "~~~~~~~~~~~~~Form4~~~~~~~~~~~~~~~" << std::endl;
        form4 = intern.makeForm("other", "Form4");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(...)
    {
        std::cout << "Type is not found" << std::endl;
    }
    delete form1;
    delete form2;
    delete form3;
    delete form4;
    return 0;
}
