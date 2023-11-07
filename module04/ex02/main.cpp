/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:32:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/06 10:26:50 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
   const AAnimal* j = new Dog();
   const AAnimal* i = new Cat();
   j->makeSound();
   i->makeSound();
   
   delete j;
   delete i;
   return 0;
}
