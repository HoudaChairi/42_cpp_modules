/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:33:52 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/12 17:02:10 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
 : AForm("default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
     : AForm(name, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cp) 
    : AForm(cp) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ob)
{
    if (this != & ob)
        AForm::operator=(ob);
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() <= this->getExecuteGrade() && this->getIsSigned())
    {
        std::cout << "*Drilling noises*" << std::endl;
        srand((unsigned int) time(0));
        int number = (rand() % 100);
        if (number % 2 == 0)
            std::cout << this->getName() << " has been robotomized successfully" << std::endl;
        else 
            std::cout << this->getName() << " Robotomy failed" << std::endl;
    }
    else
        throw GradeTooLowException();
}
