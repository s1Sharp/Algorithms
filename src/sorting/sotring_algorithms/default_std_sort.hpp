#pragma once
#include <algorithm>
#include "sorting.h"

// default_std::Sort
template <typename _T> void default_std_sort(std::vector<_T>& v, int n);

template <typename _T>
void default_std_sort(std::vector<_T>& v, int n=0)
{
    std::sort(std::begin(v), std::end(v));
}