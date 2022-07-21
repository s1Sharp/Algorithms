#pragma once
#include "sorting.h"

// shellSort
template <typename _T> void shell_sort(std::vector<_T>& v, int n);


template <typename _T>
void shell_sort(std::vector<_T>& v, int n = 0)
{
    for(int step = n/2; step > 0; step /= 2) {
        for (int i = step; i < n; i += 1) {       
            int j = i;
            while(j >= step && v[j - step] > v[i]) {
                std::swap(v[j], v[j - step]);
                j-=step;
            }
        }
    }
}
