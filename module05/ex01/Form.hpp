/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:51:06 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/11 16:02:41 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool             _isSigned;
        const int        _signGrade;
        const int        _executeGrade;
    public:
        Form();
        Form(const std::string name, const int signGrade, const int executeGrade);
        Form(const Form& copy);
        Form& operator=(const Form& obj);
        ~Form();
        
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat& bCrat);
        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw()
                {
                    return ("Grade is too high!");
                }
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw()
                {
                    return ("Grade is too low!");
                }
        };
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif