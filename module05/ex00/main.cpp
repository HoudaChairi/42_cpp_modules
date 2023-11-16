/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:38 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/15 12:31:23 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat bcrat("Sokrate", 2);
        
        std::cout << bcrat;
        bcrat.decrementGrade();
        std::cout << "After decrementing: " << bcrat;
        bcrat.incrementGrade();
        std::cout << "After incrementing: " << bcrat;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;  
    }
}
