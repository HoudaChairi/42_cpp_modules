/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:16:55 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/16 12:16:13 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        //canonical Form
        Intern();
        Intern(const Intern& cp);
        Intern& operator=(const Intern& ob);
        ~Intern();
        // ~~~~~~~~~~~~ //
        AForm* makeForm(const std::string& type, const std::string &nameForm);
        AForm* shrubberyForm(const std::string &nameForm);
        AForm* robotomyForm(const std::string &nameForm);
        AForm* pardonForm(const std::string &nameForm);
};

typedef AForm* (Intern::*FormPtr)(const std::string&);
typedef AForm* (Intern::*Forms[3])(const std::string&);

#endif