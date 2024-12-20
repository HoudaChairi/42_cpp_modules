/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:43:09 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 11:20:35 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
    : AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cp) 
    : AForm(cp) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ob)
{
    if (this != & ob)
        AForm::operator=(ob);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    if (!this->getIsSigned())
        throw SignedFormException();

    std::ofstream file(this->getName() + "_shrubbery", std::ios::trunc);
    if (file.is_open()) 
    {
        file << "    oxoxoo    ooxoo " << std::endl 
        << "   ooxoxo oo  oxoxooo " << std::endl
        << "  oooo xxoxoo ooo ooox " << std::endl 
        << "  oxo o oxoxo  xoxxoxo "<< std::endl
        << "   oxo xooxoooo o ooo " << std::endl 
        << "     ooo/oo/  /o/o " << std::endl 
        << "        /  // /" << std::endl 
        << "         |   /" << std::endl 
        << "         |  |" << std::endl
        << "         |  |" << std::endl 
        << "         |  |" << std::endl 
        << "  _______|  |___"<< std::endl;
    }
    else
        std::cout << "Unable to open file";
}
