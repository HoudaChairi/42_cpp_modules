/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:38 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/15 18:35:18 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bc("Sokrate", 1);
        Form form("form", 5, 10);
        std::cout << bc;
        std::cout << form;
        form.beSigned(bc);
        std::cout << "check was signed? => " << form.getIsSigned() << std::endl;
        bc.signForm(form);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;  
    }
}
