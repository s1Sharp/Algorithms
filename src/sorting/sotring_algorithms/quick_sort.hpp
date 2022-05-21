#pragma once
#include "sorting.h"

// quickSort
template <typename _T> void quick_sort(std::vector<_T>& v, int n);

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
template <typename _T>
int _partition(std::vector<_T>& v, int low, int high)
{
    _T pivot = v[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (v[j] < pivot)
        {
            i++; // increment index of smaller element
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
v[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
template <typename _T>
void _quickSort(std::vector<_T>& v, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = _partition(v, low, high);
 
        // Separately sort elements before
        // partition and after partition
        _quickSort(v, low, pi - 1);
        _quickSort(v, pi + 1, high);
    }
}

template <typename _T>
void quick_sort(std::vector<_T>& v, int n = 0)
{
    _quickSort(v, 0, v.end() - v.begin() - 1);
}
 


