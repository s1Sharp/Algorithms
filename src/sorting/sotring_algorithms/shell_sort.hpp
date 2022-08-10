#pragma once
#include "sorting.h"

// shellSort
template <typename _T> void shell_sort(std::vector<_T>& v, int n);


template <typename _T>
void shell_sort(std::vector<_T>& v, int n = 0)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements v[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add v[i] to the elements that have been gap sorted
            // save v[i] in temp and make a hole at position i
            _T temp = v[i];

            // shift earlier gap-sorted elements up until the correct
            // location for v[i] is found
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            // put temp (the original v[i]) in it`s correct location
            v[j] = temp;
        }
    }
}
