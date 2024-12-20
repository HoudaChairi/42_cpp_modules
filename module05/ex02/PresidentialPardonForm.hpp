/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:32:12 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/15 18:54:35 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &name);
        PresidentialPardonForm(const PresidentialPardonForm& cp);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& ob);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
};

#endif