/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:46:08 by yelousse          #+#    #+#             */
/*   Updated: 2023/04/08 16:06:00 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::string data;

    if (ac == 2)
    {
        std::string line, token;
        std::ifstream input_file("data.csv");
        std::map<std::string, float> data;
        std::string filename = av[1];
        std::ifstream input_file(filename);
        if (!input_file.is_open())
        {
            std::cout << "Error opening data.csv " << std::endl;
            return 1;
        }
        std::getline(input_file, line);
        while(std::getline(input_file, line))
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
        input_file.close();
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
        while(std::getline(input_file, line))
        {
            std::cout << line << std::endl;
        }
        input_file.close();
    }
    else
        std::cout << "Error: could not open file.";
    return 0;
}