#pragma once
#include "sorting.h"

// bubbleSort
template <typename _T> void bubble_sort(std::vector<_T>& v, int n);
template <typename _T> void bubble_sort_optimized(std::vector<_T>& v, int n);


template <typename _T>
void bubble_sort(std::vector<_T>& v, int n = 0)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
}


template <typename _T>
void bubble_sort_optimized(std::vector<_T>& v, int n = 0)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            if (v[j] > v[j+1])
            {
            std::swap(v[j], v[j+1]);
            swapped = true;
            }
        }
 
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}