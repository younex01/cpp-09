/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:34:58 by yelousse          #+#    #+#             */
/*   Updated: 2023/04/10 21:56:42 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int end, tmp, start = -1;
        std::string k, str = av[1];

        std::stack<std::string> s;
        tmp = -1;
        end = 0;
        while(end != -1)
        {
            end = tmp;
            start = end + 1;
            end = str.find(" ", start);
            std::cout << str.substr(start, end - start) << std::endl;
            k = str.substr(start, end - start);
            c = k.c_str();
            // if (c.c_str() >= '0' )
            if (((*)c) >= "0")
            tmp = end;
        }
    }
    return (0);
}