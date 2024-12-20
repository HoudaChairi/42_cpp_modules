/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:37:36 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 11:48:30 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
    : AForm(name, 25, 5)  {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cp) 
    : AForm(cp) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ob)
{
    if (this != &ob)
        AForm::operator=(ob);
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    if (!this->getIsSigned())
        throw SignedFormException();

    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

