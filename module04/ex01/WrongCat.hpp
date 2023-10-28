/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:44:32 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/23 11:59:23 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp" 

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string _type);
        WrongCat(const WrongCat& copy);
        WrongCat& operator=(const WrongCat& obj);
        ~WrongCat();
        void makeSound() const;
};



#endif