#pragma once
#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include "timer_util.h"


template <typename T>
void rangom_vector(std::vector<T>& v)
{
    using std::setprecision;


    const T FLOAT_MAX = static_cast<T>(v.capacity() / 2);
    const T FLOAT_MIN = -static_cast<T>(v.capacity() / 2);

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