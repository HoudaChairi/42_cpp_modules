/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:31:19 by hchairi           #+#    #+#             */
/*   Updated: 2023/09/15 11:04:05 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string* stringPtr = &s;
    std::string& stringRef = s;

    std::cout << &s << std::endl;
    std::cout << stringPtr << std::endl;
    std::cout << &stringRef << std::endl;

    std::cout << s << std::endl;
    std::cout << *stringPtr << std::endl;
    std::cout << stringRef << std::endl;
    return (0);
}