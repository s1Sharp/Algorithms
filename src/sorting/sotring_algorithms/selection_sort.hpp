#pragma once
#include "sorting.h"

// selectionSort
template <typename _T> void selection_sort_std(std::vector<_T>& v, int n);
template <typename _T> void selection_sort(std::vector<_T>& v, int n);

template <typename _T>
void selection_sort_std(std::vector<_T>& v, int n = 0)
{
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::iter_swap(it, std::min_element(it, v.end()));
    }
}

template <typename _T>
void selection_sort(std::vector<_T>& v, int n = 0)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n - 1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
        if (v[j] < v[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        std::swap(v[min_idx], v[i]);
    } 
};