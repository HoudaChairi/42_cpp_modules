/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:49 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 12:14:05 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& cp)
{
    *this = cp;
}

Intern& Intern::operator=(const Intern& ob)
{
    if (this != &ob)
        return (*this);
    return (*this);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
AForm* Intern::shrubberyForm(const std::string &nameForm)
{
    return (new ShrubberyCreationForm(nameForm));
}

AForm* Intern::robotomyForm(const std::string &nameForm)
{
    return (new RobotomyRequestForm(nameForm));
}

AForm* Intern::pardonForm(const std::string &nameForm)
{
    return (new PresidentialPardonForm(nameForm));
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
AForm* Intern::makeForm(const std::string &type, const std::string &nameForm)
{
    FormPtr shrubberyPtr = &Intern::shrubberyForm;
    FormPtr requestPtr = &Intern::robotomyForm;
    FormPtr  pardonPtr = &Intern::pardonForm;

    std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Forms arrForms = {shrubberyPtr, requestPtr, pardonPtr};
    int i = 0;
    for(; i < 3; i++)
    {
        if (type == arr[i])
        {
            std::cout << "Intern creates " << nameForm << std::endl;
            return (this->*arrForms[i])(nameForm);
        }
    }
    if (i == 3)
        throw NULL;
    return (NULL);
}
