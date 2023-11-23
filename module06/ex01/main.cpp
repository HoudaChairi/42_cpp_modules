/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:29:04 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/23 10:53:56 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data    d;
    std::cout << d.getName() << std::endl;

    // Serialize the address of the Data object
    uintptr_t   s = Serializer::serialize(&d);

    // Deserialize the serialized value
    Data        *ptr = Serializer::deserialize(s);
    
    if (ptr == &d)
        std::cout << "EQUAL" << std::endl;
    else
        std::cout << "NOT EQUAL" << std::endl;

    std::cout << ptr->getName() <<std::endl;
    return (0);
}
