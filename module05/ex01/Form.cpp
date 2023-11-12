/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:50:56 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/11 16:02:33 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(1), _executeGrade(1) {}

Form::~Form() {}

Form::Form(const std::string name, const int signGrade, const int executeGrade) : 
_name(name),
_isSigned(false),
_signGrade(signGrade),
_executeGrade(executeGrade) 
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) :
_name(copy._name),
_isSigned(copy._isSigned),
_signGrade(copy._signGrade),
_executeGrade(copy._executeGrade) {}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
        _isSigned = obj._isSigned;
    return (*this);
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getIsSigned() const 
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return (_signGrade);
}

int Form::getExecuteGrade() const
{
    return (_executeGrade);
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
    os << "Name: " << Form.getName() << std::endl;
    os << "Is signed: " << Form.getIsSigned() << std::endl;
    os << "Sign grade: " << Form.getSignGrade() << std::endl;
    os << "Execute grade: " << Form.getExecuteGrade() << std::endl;
    return (os);
}

// if (grade de bureauCrat <= _signGrade : _isSigned = true else throw)
void Form::beSigned(const Bureaucrat& bCrat)
{
    if (bCrat.getGrade() > _signGrade) 
        throw GradeTooLowException();
    _isSigned = true;
}
