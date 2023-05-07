/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:46:05 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/07 00:46:22 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_digit(std::string str)
{
    std::string::iterator i = str.begin();
    int c = 0;
    while(i != str.end())
    {
        if (*i >= '0' && *i <= '9')
        {
            c += (*i);
            i++;
        }
        else
            return (0);
    }
    if (c == '0')
        return (0);
    return (1);
}

int check_value(std::string str)
{
    std::string::iterator i = str.begin();
    int c = 0;
    int j = 0;
    int check_space;
    int check_words = 0;
    while(i != str.end())
    {
        check_space = 0;
        while (*i == ' ')
        {
            i++;
            check_space++;
        }
        if ((*i >= '0' && *i <= '9') || *i == '.')
        {
            if (*i == '.')
                j++;
            c += (*i);
            i++;
        }
        else
            return (0);
        if ((check_space > 0))
        {
            check_words++;
            if (check_words >= 1)
                return (0);
        }
    }
    if (c == '0' || j > 1)
        return (0);
    return (1);
}

int check_line(std::string line)
{
    std::string::iterator it;
    it = line.begin();
    while (it != line.end())
    {
        if (*it == ' ' || *it == '\t')
            it++;
        else
            return (1);
    }
    return (0);
}

int leap_year(int year)
{
    if ((year % 400 == 0 || year % 100 != 0) &&(year % 4 == 0))
        return (1);
    else
        return (0);
}

int check_value_space(std::string value)
{
    std::string::iterator it;
    it = value.begin();
    if (*it != ' ')
        return (0);
    else
        return (1);
}

int check_date(std::string str)
{
    if (str.empty())
        return (0);
    int count = std::count(str.begin(), str.end(), '-');
    std::string::iterator it = str.begin();
    if(count != 2)
        return (0);
    if (str.size() == 11)
    {
        while (it != str.end())
            it++;
        it--;
        if (*it == ' ')
            return (1);
    }
    return (0);
}