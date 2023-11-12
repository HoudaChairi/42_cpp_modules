/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:38 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/11 11:14:14 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::string str = "Houda";
    try 
    {
        Bureaucrat bureau("hi", 5);
        bureau.decrementGrade();
        std::cout << bureau.getGrade() << std::endl;
        std::cout << bureau;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;  
    }
    // catch(Bureaucrat::GradeTooHighException &e)
    // {
    //   std::cout << e.what() << std::endl;  
    // }
    // catch(Bureaucrat::GradeTooLowException &e)
    // {
    //   std::cout << e.what() << std::endl;  
    // }
}
