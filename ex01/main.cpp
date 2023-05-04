/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:34:58 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/04 01:16:23 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int end, rep = 0, tmp, start = -1;
        std::string k, str = av[1];
        std::stack<std::string> s;
        tmp = -1;
        end = 0;
        int result, check = 0;
        while(end != -1)
        {
            end = tmp;
            start = end + 1;
            end = str.find(" ", start);
            // std::cout << str.substr(start, end - start) << std::endl;
            k = str.substr(start, end - start);
            if(k.find_first_of("0123456789/*-+") != std::string::npos && k.size() == 1)
            {
                if (k.find_first_of("/*-+") != std::string::npos)
                {
                    rep++;
                    if (check < 2 || rep >= 2)
                    {
                        std::cout << "Error" << std::endl;
                        return (1);
                    }
                    result = std::atoi(s.top().c_str());
                    s.pop();
                    if (k.find_first_of("/") != std::string::npos)
                        result = std::atoi(s.top().c_str()) / result;
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
                return (1);
            }
            tmp = end;
        }
        // std::cout << "<----------->\n";
        if(s.size() != 0)
        {
            std::cout << s.top() << std::endl;
            s.pop();
        }
        std::cout << s.size() << std::endl;
        
    }
    return (0);
}