/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:35 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/12 17:03:54 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
        Bureaucrat();

    public:
        ~Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& obj);
        
        std::string getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw()
                {
                    return "Grade is too high!";
                }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw() 
                {
                    return "Grade is too low!";
                }
        };

        void signForm(Form& form);//why not const // because beSigned modifier

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif