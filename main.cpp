/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <youness@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:46:08 by yelousse          #+#    #+#             */
/*   Updated: 2023/04/09 09:35:54 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::string data;

    if (ac == 2)
    {
        std::string line, token;
        std::ifstream input_data("data.csv");
        std::map<std::string, float> data;
        std::string filename = av[1];
        // std::cout << filename << std::endl;
        std::ifstream input_file(filename.c_str());
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
                // std::cout << date << "+" << value << std::endl;
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
        if (!input_file.is_open())
        {
            std::cout << "Error opening file " << filename << std::endl;
            return 1;
        }
        std::getline(input_file, line);
        while(std::getline(input_file, line))
        {
            size_t pos = 0;
            std::string date, value;
            float nb, result;
            while ((pos = line.find("|")) != std::string::npos) {
                date = line.substr(0, pos);
                value = line.erase(0, pos + 1);
                nb = std::atof(value.c_str());
                if (nb > 1000)
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