/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:14:01 by laura             #+#    #+#             */
/*   Updated: 2024/03/24 20:46:45 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cerr << "\033[1;31mError : please give me a string in this format : 'number number operation...'" << std::endl;
        return 1;
    }
    
    std::string line = argv[1];
    RPN calculator(line);

    while (calculator.getError() != 1)
    {  
        std::stack<long> resultStack = calculator.getStack();
        if (resultStack.size() != 1) 
        {
            std::cerr << "\033[1;31mError : Invalid expression" << std::endl;
            return 1;
        }
        else {
            std::cout << resultStack.top() << std::endl;
            return 0;
        }
    }
    return 0;
}
