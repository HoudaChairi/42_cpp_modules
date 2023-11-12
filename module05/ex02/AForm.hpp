/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:51:06 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/12 10:22:26 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool             _isSigned;
        const int        _signGrade;
        const int        _executeGrade;
    public:
        AForm();
        AForm(const std::string name, const int signGrade, const int executeGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& obj);
        virtual ~AForm();
        
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

        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif