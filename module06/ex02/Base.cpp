/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:18:13 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 11:15:29 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
    srand(time(0));
    int randNum = rand() % 10;
    if (randNum >= 0 && randNum <= 3)
        return (new A);
    else if (randNum > 3 && randNum <= 6)
        return (new B);
    else
        return (new C);
    return NULL;
}

void identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(ptr) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(ptr) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& ref)
{
    try
    {
        A& a = dynamic_cast<A&>(ref);
        std::cout << "A" << std::endl;    
        (void)a;
    }
    catch (std::bad_cast&) 
    {
        try
        {
            B& b = dynamic_cast<B&>(ref);
            std::cout << "B" << std::endl; 
            (void)b;
        }
        catch (std::bad_cast&)
        {
            try
            {
                C &c = dynamic_cast<C&>(ref);
                std::cout << "C" << std::endl;
                (void)c;
            }
            catch(std::bad_cast&)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}