/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:46:08 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/06 05:33:22 by yelousse         ###   ########.fr       */
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
    std::string::iterator it = str.begin();
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

int main(int ac, char **av)
{
    std::string data;

    if (ac == 2)
    {
        std::string line, token;
        std::map<std::string, float> data;
        std::string filename = av[1];
        std::ifstream input_data("data.csv");
        //read the data in map data
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
        // read the input file
        std::ifstream input_file(filename.c_str());
        if (!input_file.is_open())
        {
            std::cout << "Error opening file " << filename << std::endl;
            return 1;
        }
        // check first line of the input file
        std::getline(input_file, line);
        if (line.compare("date | value") != 0)
        {
            std::cout << "Error in the first line of the input file: '" << line << "'" << std::endl;
            exit (0);
        }
        //check all the file
        while(std::getline(input_file, line))
        {
            if (!line.empty())
            {
                if(check_line(line) == 1)
                {   
                    size_t pos = 0;
                    int leap = 0;
                    std::string date, value, value_, tmp;
                    float nb, result = 0.0;
                    std::string year, month, day;
                    if (line.find("|") == std::string::npos)
                        std::cout << "Error: bad input => " << line << std::endl;
                    else if ((pos = line.find("|")) != std::string::npos)
                    {
                        date = line.substr(0, pos);
                        if (date.empty() || !check_date(date))
                        {
                            std::cout << "Error: bad input => " << line << std::endl;
                            leap = 1;
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
                            tmp = value;
                            value_ = value.erase(0,1);
                        }
                        // parse the value
                        if (month == "02")
                        {
                            if (std::atoi(day.c_str()) > 29)
                            {
                                std::cout << "Error: bad input => " << date << std::endl;
                                leap = 1;
                            }
                            else if (std::atoi(day.c_str()) == 29)
                            {
                                if (!leap_year(std::atoi(year.c_str())))
                                {
                                    std::cout << "Error: bad input => " << date << std::endl;
                                    leap = 1;
                                }
                            }
                        }
                        if ((day >= "32" || month > "12" || (year <= "2009" && month <= "01" && day < "02") 
                                || year < "2009" || !check_digit(year) || !check_digit(month) || !check_digit(day) || !check_value(value_) || !check_value_space(tmp)) && !leap)
                        {
                            if (!check_value(value_) || !check_value_space(tmp))
                                std::cout << "Error: not a positive number." << std::endl;
                            else
                                std::cout << "Error: bad input => " << date << std::endl;
                        }
                        else if (nb > 1000)
                            std::cout << "Error: too large a number." << std::endl;
                        else if (nb < 0)
                            std::cout << "Error: not a positive number." << std::endl;
                        else
                        {
                            if (data[date] == 0 && !leap)
                            {
                                std::map<std::string, float>::iterator it;
                                it = data.find(date);
                                it--;
                                if (it != data.end())
                                    result = nb * it->second;
                            }
                            else
                                result = nb * data[date];
                            if (!leap)
                                std::cout << date << " => " << value << " = " << result << std::endl;
                        }
                    }
                }
            }
        }
        input_file.close();
    }
    else
        std::cout << "Error: could not open file.";
    return 0;
}