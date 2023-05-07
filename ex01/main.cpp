/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:34:58 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/07 05:20:14 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        rpn(av[1]);
    else
    {
        std::cout << "Error" << std::endl;
        exit (EXIT_FAILURE);
    }
    return (0);
}