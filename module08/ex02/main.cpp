/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:42:02 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/03 11:58:15 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "--------- MutantStack --------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "---------- std::list ---------" << std::endl;
    std::list<int> container;
    container.push_back(5);
    container.push_back(17);
    std::cout << container.back() << std::endl;
    container.pop_back();
    std::cout << container.size() << std::endl;
    container.push_back(3);
    container.push_back(5);
    container.push_back(737);
    container.push_back(0);

    std::list<int>::iterator it1 = container.begin();
    std::list<int>::iterator ite2 = container.end();
    ++it1;
    --it1;
    while (it1 != ite2) {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::cout << "---------- ******** ----------" << std::endl;
    return 0;
}
