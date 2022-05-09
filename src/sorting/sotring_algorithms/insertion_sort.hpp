#pragma once
#include "sorting.h"

// insertionSort
template <typename _T> void insertion_sort(std::vector<_T>& v, int n);


template <typename _T>
void insertion_sort(std::vector<_T>& v, int n = 0)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        _T key = v[i];
        j = i - 1;
 
        /* Move elements of v[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}