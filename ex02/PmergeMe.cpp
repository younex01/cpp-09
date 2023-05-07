/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:27:34 by yelousse          #+#    #+#             */
/*   Updated: 2023/05/07 06:14:03 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void    merge_inser_sort(T& v, int l, int r)
{
    if (r - l > 100) {
        int m = l + (r - l) / 2;
        merge_inser_sort(v, l, m);
        merge_inser_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
    insert_sort(v, l, r);
}