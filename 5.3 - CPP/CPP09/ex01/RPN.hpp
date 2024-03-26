/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:14:05 by laura             #+#    #+#             */
/*   Updated: 2024/03/24 20:44:27 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public :
		RPN(std::string param);
		RPN(RPN const &src);
		~RPN(void);
		RPN	&operator=(RPN const &src);

		std::stack<long>	getStack(void) const;
        int getError(void) const;
        void setError();

	private :
		void evaluateExpression(std::string param);
		bool performOperation(std::string token);
		void pushOperand(std::string token);

		std::stack<long> _stack;
        int _error;
};

#endif
