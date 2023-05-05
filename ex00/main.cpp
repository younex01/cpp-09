/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:46:08 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/05 03:16:39 by yelousse         ###   ########.fr       */
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
    while(i != str.end())
    {
        while (*i == ' ')
            i++;
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

int main(int ac, char **av)
{
    std::string data;

    if (ac == 2)
    {
        std::string line, token;
        std::map<std::string, float> data;
        std::string filename = av[1];
        std::ifstream input_data("data.csv");
        if (!input_data.is_open())
        {
            std::cout << "Error opening data.csv " << std::endl;
            return 1;
        }
        std::getline(input_data, line);
        while(std::getline(input_data, line))
        {
            size_t pos = 0;
            std::string date,value;
            while ((pos = line.find(",")) != std::string::npos) {
                date = line.substr(0, pos);
                value = line.erase(0, pos + 1);
                data[date] = std::atof(value.c_str());
            }
        }
        input_data.close();
        // std::map<std::string, float>::iterator it;
        // it = data.begin();
        // while(it != data.end())
        // {
        //     std::cout << it->first << "," << it->second << std::endl;
        //     it++;
        // }
        std::ifstream input_file(filename.c_str());
        if (!input_file.is_open())
        {
            std::cout << "Error opening file " << filename << std::endl;
            return 1;
        }
        std::getline(input_file, line);
        if (line.compare("date | value") != 0)
        {
            std::cout << "Error in the first line of the input file: '" << line << "'" << std::endl;
            exit (0);
        }
        while(std::getline(input_file, line))
        {
            size_t pos = 0;
            std::string date, value;
            float nb, result = 0.0;
            std::string year, month, day;
            if (line.find("|") == std::string::npos || line.empty())
            {
                std::cout << "Error: bad input => " << line << std::endl;
            }
            else if ((pos = line.find("|")) != std::string::npos)
            {
                date = line.substr(0, pos);
                if (date.empty())
                {
                    std::cout << "Error: bad input => " << line << std::endl;
                }
                else
                {
                    value = line.erase(0, pos + 1);
                    nb = std::atof(value.c_str());
                    // parse the date
                    year = date.substr(0, 4);
                    day = date.substr(8, 10);
                    day = day.erase(2,4);
                    month = date.substr(5, 6);
                    month = month.erase(2,4);
                }
                // parse the value
                if (day >= "32" || month > "12" || (year <= "2009" && month <= "01" && day < "02") || !check_digit(year) || !check_digit(month) || !check_digit(day) || !check_value(value))
                {
                    if (!check_value(value))
                        std::cout << "Error: not a positive number." << std::endl;
                    else
                    {
                        std::cout << "Error: bad input => ";
                        std::cout << date << std::endl;
                    }
                }
                else if (nb > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else if (nb < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else
                {
                    if (data[date] == 0)
                    {
                        std::map<std::string, float>::iterator it;
                        it = data.find(date);
                        it--;
                        if (it != data.end())
                            result = nb * it->second;
                            // std::cout << it->second << std::endl;
                    }
                    else
                        result = nb * data[date];
                    std::cout << date << " => " << value << " = " << result << std::endl;
                }
            }
            // std::cout << line << std::endl;
        }
        input_file.close();
    }
    else
        std::cout << "Error: could not open file.";
    return 0;
}