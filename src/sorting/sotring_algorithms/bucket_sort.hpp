#pragma once
#include <vector>
#include <limits>
#include "sorting.h"

// bucketSort
template <typename _T> void bucket_sort(std::vector<_T>& v, int n);

// Function to sort v[] of
// size n using bucket sort
template <typename _T> 
void bucket_sort(std::vector<_T>& v, int n=0)
{
    _T MaxElement = *std::max_element(v.begin(), v.end());
    _T MinElement = *std::min_element(v.begin(), v.end());
    _T diff = MaxElement - MinElement + std::numeric_limits<_T>::min();

    std::vector<std::vector<_T>> bucket(10);//Create ten buckets
    for (int i = 0; i < v.size(); i++) 
    {
        int temp = (v[i]/diff + 1.f) * 5;  //Put into different buckets according to the first decimal point
        bucket[temp].push_back(v[i]);
    }
    v.clear(); //Clear the original unordered array
    for (auto vec:bucket)
    {
        if (!vec.empty()) {
            sort(vec.begin(),vec.end()); //Sort non-empty buckets
            v.insert(v.end(),vec.begin(), vec.end()); //Put the original array in the order of the bucket
        }
    }
}