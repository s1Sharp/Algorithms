#pragma once
#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <functional>
#include <utility>
#include <assert.h>
#include "timer_util.h"





template <typename _T, typename SortCallFunc> // typename _Comparator>
double sort_vector(std::vector<_T> v, SortCallFunc sotring)
{
    t.start();
    // sortings call
    sotring(std::begin(v), std::end(v));
    t.end();

    // asserting vector sorting
    assert(std::is_sorted(std::begin(v), std::end(v)))

    return t.elapsedMilliseconds();
}

template <typename _T>
void rangom_vector(std::vector<_T>& v)
{

    using std::setprecision;


    const _T FLOAT_MAX = static_cast<_T>(v.capacity() / 2);
    const _T FLOAT_MIN = -static_cast<_T>(v.capacity() / 2);

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);
    //distr(eng)

    generate(v.begin(), v.end(), 
            [&eng, &distr] () mutable  {
                auto dist = distr(eng);
                //std::cout << dist << std::endl;
                return dist;
            });

    return;
}