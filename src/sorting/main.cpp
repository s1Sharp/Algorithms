#include "sorting.h"

// sorting functions
// selectionSort
#include "selection_sort.hpp"
#include "merge_sort.hpp"
#include "bubble_sort.hpp"

#define STRINGIZE(x) #x

#define TYPE float
#define SIZE 10000


auto benchmark = [](auto v,  auto f, auto sort_type) -> double
{
    static Timer timer;
    auto local_v {v};
    
    int n = static_cast<int>(v.end() - v.begin());
    assert(n >= 0);
    if (n == 0)
    {
        return -1.f;
    }

    timer.start();
    f(local_v, n);
    timer.stop();

    // asserting vector sorting
    bool is_sorted = std::is_sorted(std::begin(local_v), std::end(local_v));
    m_Assert(is_sorted, "vector not sorted");
    is_sorted ? std::cout << "sorted by " << sort_type << std::endl : std::cout << "not sorted by " << sort_type << std::endl;
    double time =  timer.elapsedMilliseconds();
    return time;
};  

template <typename _bechmark_type>
auto benchmark_sorting_list(_bechmark_type sorting_list) -> std::vector<std::pair<std::string, double>>
{
    std::vector<TYPE> v(SIZE);
    rangom_vector(v);
    std::vector<std::pair<std::string, double>> vector_pairs;

    for (auto& sort_func : sorting_list){
        vector_pairs.push_back(
                    std::make_pair<std::string, double>(
                        sort_func.second, // function name
                        benchmark(v, sort_func.first, sort_func.second)) // elapsed time 'ms'
        );
    }

    return vector_pairs;
}


int main()
{
    std::vector sorting_list = {
        std::make_pair(selection_sort<TYPE>, STRINGIZE(selection_sort)),
        std::make_pair(selection_sort_std<TYPE>, STRINGIZE(selection_sort_std)),
        std::make_pair(merge_sort_std<TYPE>, STRINGIZE(merge_sort_std)),
        std::make_pair(bubble_sort<TYPE>, STRINGIZE(bubble_sort)),
        std::make_pair(bubble_sort_optimized<TYPE>, STRINGIZE(bubble_sort_optimized)),
        
    };

    auto sorting_result = benchmark_sorting_list(sorting_list);
    for (auto& s : sorting_result)
    {
        std::cout<< "sorting algorithm: "<< s.first << " \t\telapsed time: " << s.second << " ms" << std::endl;
    }
    
    return 0;
}