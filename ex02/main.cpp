#include "PmergeMe.hpp"

template<typename T>
void insert_sort(T& v, int l, int r)
{
    for (int i = l; i < r; i++)
    {
       int tmp = v[i + 1];
       int j = i + 1;
       while(l < j && tmp < v[j - 1])
       {
            v[j] =  v[j - 1];
            j--;
       }
       v[j] = tmp;
    }
}

template<typename T>
void merge(T& v, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // 
    int n2 = r - m;

    T L(n1);
    T R(n2);

    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void    merge_sort(T& v, int l, int r)
{
    if (r - l > 100) {
        int m = l + (r - l) / 2;
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
    insert_sort(v, l, r);
}

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
        struct timeval start, end;
        struct timeval start_, end_;
        long seconds, useconds;
        long seconds_, useconds_;
        int i = 1;

        std::vector<int> v;
        std::deque<int> q;

        std::vector<int>::const_iterator it;
        std::deque<int>::const_iterator it_;
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
        // it_ = q.begin();
        // while(it_ != q.end())
        // {
        //     std::cout << (*it_) << " " ;
        //     it_++;
        // }
        // std::cout << v.size() << std::endl;
        gettimeofday(&start, NULL);
        merge_sort(v, 0, v.size() - 1);
        gettimeofday(&end, NULL);

        gettimeofday(&start_, NULL);
        merge_sort(q, 0, q.size() - 1);
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