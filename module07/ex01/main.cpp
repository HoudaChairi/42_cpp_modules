/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:03:54 by hchairi           #+#    #+#             */
/*   Updated: 2023/11/26 15:59:08 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T ele)
{
    std::cout << ele << std::endl;
}

void square(int& x)
{
    x *= x;
    std::cout << x << " ";
}

int main()
{
    std::cout << "~~~array of integers~~~" << std::endl;
    int arr2[5] = {1, 2, 3, 4, 5};
    iter(arr2, 5, print<int>);
    iter(arr2, 5, square);
    
    std::cout << std::endl << "~~~array of strings~~~" << std::endl;
    std::string arr1[5] = {"one", "two", "three", "four", "five"};
    iter(arr1, 5, print<std::string>);

    std::cout << "~~~array of characters~~~" << std::endl;
    char arr3[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(arr3, 5, print<char>);
    
    return (0);
}
