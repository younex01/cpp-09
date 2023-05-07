/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:35:06 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/07 05:09:04 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void rpn(std::string str)
{
    std::stack<std::string> s;
    std::string k;
    int end, rep = 0, tmp, start = -1;
    int result, check = 0;
    tmp = -1;
    end = 0;
    while(end != -1)
    {
        end = tmp;
        start = end + 1;
        end = str.find(" ", start);
        k = str.substr(start, end - start);
        if(k.find_first_of("0123456789/*-+") != std::string::npos && k.size() == 1)
        {
            if (k.find_first_of("/*-+") != std::string::npos)
            {
                rep++;
                if (check < 2 || (rep >= 2 && s.size() <= 1))
                {
                    std::cout << "Error" << std::endl;
                    exit (EXIT_FAILURE);
                }
                result = std::atoi(s.top().c_str());
                s.pop();
                if (k.find_first_of("/") != std::string::npos)
                {
                    if (result == 0)
                    {
                        std::cout << "Error" << std::endl;
                        exit (EXIT_FAILURE);
                    }
                    else
                        result = std::atoi(s.top().c_str()) / result;
                }
                if (k.find_first_of("+") != std::string::npos)
                    result = std::atoi(s.top().c_str()) + result;
                if (k.find_first_of("-") != std::string::npos)
                    result = std::atoi(s.top().c_str()) - result;
                if (k.find_first_of("*") != std::string::npos)
                    result = std::atoi(s.top().c_str()) * result;
                s.pop();
                s.push(std::to_string(result));
            }
            else
            {
                rep = 0;
                s.push(k);
                check++;
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            exit (EXIT_FAILURE);
        }
        tmp = end;
    }
    if(s.size() == 1)
    {
        std::cout << s.top() << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
        exit (EXIT_FAILURE);
    }
}
