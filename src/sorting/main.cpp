#include <iostream>
#include <vector>
#include <ctime>
#include "sorting.h"

#define STRINGIZE(x) #x

#define TYPE float
#define SIZE 10000

template <typename _T>
void selectionSort(std::vector<_T>& v, size_t n = 0)
{   
    assert(n >= 0);
    if (n == 0 && n == (v.end() - v.begin()))
    {
        return;
    }

    n = static_cast<size_t>(v.end() - v.begin());

    size_t i, j, min_idx;
  
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

auto benchmark = [](auto v,  auto f, auto sort_type) -> double
{
    static Timer timer;
    timer.start();
    f(v, 0);
    timer.stop();

    // asserting vector sorting
    bool is_sorted = std::is_sorted(std::begin(v), std::end(v));
    assert(is_sorted);
    is_sorted ? std::cout << "sorted by " << sort_type << std::endl : std::cout << "not sorted by " << sort_type << std::endl;
    double time =  timer.elapsedMilliseconds();
    return time;
};  


int main()
{

    std::vector<TYPE> v(SIZE);
    rangom_vector(v);

    std::cout<< "elapsed time " << benchmark(v, selectionSort<TYPE>, STRINGIZE(selectionSort)) << " ms" << std::endl;
    
    return 0;
}