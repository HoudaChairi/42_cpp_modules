/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:06 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 11:17:19 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() 
{
   Base* p = generate();
   std::cout << "type by pointer: ";
   identify(p);
   std::cout << "type by reference: ";
   identify(*p);
   delete p;
   return 0;
}