/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:32:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/10/24 19:35:47 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
    
//     delete j;//should not create a leak
//     delete i;

//     return 0;
// }

int main()
{
    Dog dog;
    Cat cat;
    Animal arr[10];

    for(int i = 0; i < 10; i++)
    {
        if (i < 5)
            arr[i] = Dog("dog");
        else
            arr[i] = Cat("cat");
    }
    // for(int i = 0; i < 4; i++)
    // {
    //     delete arr[i];    
    // }
    return (0);
}