/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:50:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 11:41:26 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(1), _executeGrade(1) {}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade) : 
_name(name),
_isSigned(false),
_signGrade(signGrade),
_executeGrade(executeGrade) 
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) :
_name(copy._name),
_isSigned(copy._isSigned),
_signGrade(copy._signGrade),
_executeGrade(copy._executeGrade) {}

AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
        _isSigned = obj._isSigned;
    return (*this);
}

//~~~~~~~~~~~ getters ~~~~~~~~~~~//
std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getIsSigned() const 
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return (_signGrade);
}

int AForm::getExecuteGrade() const
{
    return (_executeGrade);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << "Name: " << AForm.getName() << std::endl;
    os << "Is signed: " << AForm.getIsSigned() << std::endl;
    os << "Sign grade: " << AForm.getSignGrade() << std::endl;
    os << "Execute grade: " << AForm.getExecuteGrade() << std::endl;
    return (os);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void AForm::beSigned(const Bureaucrat& bCrat)
{
    if (bCrat.getGrade() > _signGrade) 
        throw GradeTooLowException();
    _isSigned = true;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
const char  *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}
const char  *AForm::SignedFormException::what() const throw()
{
    return ("The form is not signed.");
}