/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 05:25:26 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/07 06:14:15 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.cpp"

int check_string(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(!(std::isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        std::vector<int> v;
        std::deque<int> q;
        std::vector<int>::const_iterator it;
        std::deque<int>::const_iterator it_;
        struct timeval start, end;
        struct timeval start_, end_;
        long seconds, useconds;
        long seconds_, useconds_;
        int i = 1;

        while (i < ac)
        {
            if (std::atoi(av[i]) > 0 && check_string(av[i]))
            {
                v.push_back(std::atoi(av[i]));
                q.push_back(std::atoi(av[i]));
            }
            else
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
            i++;
        }
        std::cout << "before: ";
        it = v.begin();
        while(it != v.end())
        {
            std::cout << (*it) << " " ;
            it++;
        }
        gettimeofday(&start, NULL);
        merge_inser_sort(v, 0, v.size() - 1);
        gettimeofday(&end, NULL);

        gettimeofday(&start_, NULL);
        merge_inser_sort(q, 0, q.size() - 1);
        gettimeofday(&end_, NULL);

        std::cout << std::endl << "After: ";
        it = v.begin();
        while(it != v.end())
        {
            std::cout << (*it) << " " ;
            it++;
        }
        std::cout << std::endl;

        useconds = (end.tv_usec - start.tv_usec) ;
        seconds = (end.tv_sec - start.tv_sec) ;
        double time = seconds * 1000000.00 + useconds;
        std::cout << "Time to process a range of " << v.size() << " elements with std::vector " << time  << " us" << std::endl;

        useconds_ = (end_.tv_usec - start_.tv_usec) ;
        seconds_ = (end_.tv_sec - start_.tv_sec) ;
        double time_ = seconds_ * 1000000.00 + useconds_;
        std::cout << "Time to process a range of " << q.size() << " elements with std::deque " << time_  << " us" << std::endl;
    }
    else
        std::cout << "Error" << std::endl;
    return (0);
}