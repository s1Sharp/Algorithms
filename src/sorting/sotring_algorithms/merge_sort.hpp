#pragma once
#include "sorting.h"

// mergeSort
template <typename _T> void merge_sort_std(std::vector<_T>& v, int n);

template <typename _T>
void merge_sort_std(std::vector<_T>& v, int n = 0)
{
    if (v.size() <= 1) {
        return;
    }
    auto middle_elem = v.begin() + v.size() / 2;
    std::vector left(v.begin(), middle_elem);
    std::vector right(middle_elem, v.end());
    merge_sort_std(left);
    merge_sort_std(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), v.begin());
}