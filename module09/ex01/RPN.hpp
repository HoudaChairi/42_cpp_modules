/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:39:20 by hchairi           #+#    #+#             */
/*   Updated: 2023/12/16 17:30:25 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<std::string> _stack;
		std::string				_form;
	public:
		RPN();
		RPN(const std::string&);
		RPN(const RPN& cp);
		RPN& operator=(const RPN& ob);
		~RPN();

		bool	isOp(char c);
		void	calcul(char op);
		int		getResult();

		std::stack<std::string> getStack() const;
};

#endif