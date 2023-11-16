/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:01:35 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 12:11:10 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    public:
        //canonical Form
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& obj);
        ~Bureaucrat();
        // Getters:
        std::string getName() const;
        int getGrade() const;
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
        void incrementGrade();
        void decrementGrade();
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
        class GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
        void signForm(AForm& Aform);
        void executeForm(AForm const & Aform);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif