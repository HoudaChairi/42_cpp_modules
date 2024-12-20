/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:32:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/06 17:48:03 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
   Cat cat;
   Dog dog;

   Animal *a1 = &cat;
   Animal *a2 = &dog;

   Animal *arr[] = {a1, a2};
   for (int i = 0; i < 2; i++)
      arr[i]->makeSound();
   return 0;
}

