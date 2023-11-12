/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:38 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/11 16:47:27 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat bc("Seqrat", 22);
        Form form("form", 5, 10);
        std::cout << form;
        bc.signForm(form);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;  
    }
}
