#include "sorting.h"

// sorting functions
#include "default_std_sort.hpp"
#include "selection_sort.hpp"
#include "merge_sort.hpp"
#include "bubble_sort.hpp"
#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "quick_sort.hpp"
#include "bucket_sort.hpp"
#include "shell_sort.hpp"

#define STRINGIZE(x) #x

#define TYPE float

static const int BENCH_NUMBER = 5;
static const size_t SIZE = 30000LL;

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
    m_Assert(is_sorted, std::string("vector not sorted by ") + std::string(sort_type));
    is_sorted ? std::cout << "sorted by " << sort_type << std::endl : std::cout << "not sorted by " << sort_type << std::endl;
    double time =  timer.elapsedMilliseconds();
    return time;
};  

template <typename _bechmark_type>
auto benchmark_sorting_list(_bechmark_type sorting_list, const int bench_number_max) -> std::map<std::string, std::pair<std::string, double>>
{
    std::map<std::string, std::pair<std::string, double>> vector_pairs;
    std::vector<TYPE> v(SIZE);

    for (auto& sort_func : sorting_list) {
            vector_pairs[sort_func.second] = std::make_pair<std::string, double>(
                                                sort_func.second, // function name
                                                0) // elapsed time 'ms'
                                                ;
    }

    for (int bench_number = 0; bench_number < bench_number_max; bench_number++)
    {
        rangom_vector(v);
        for (auto& sort_func : sorting_list){
            vector_pairs[sort_func.second].second += benchmark(v, sort_func.first, sort_func.second);
        }
    }
    return vector_pairs;
}


int main()
{
    std::vector sorting_list = {
        std::make_pair(default_std_sort<TYPE>,          STRINGIZE(default_std_sort)),
        std::make_pair(selection_sort<TYPE>,            STRINGIZE(selection_sort)),
        std::make_pair(selection_sort_std<TYPE>,        STRINGIZE(selection_sort_std)),
        std::make_pair(merge_sort_std<TYPE>,            STRINGIZE(merge_sort_std)),
        std::make_pair(bubble_sort<TYPE>,               STRINGIZE(bubble_sort)),
        std::make_pair(bubble_sort_optimized<TYPE>,     STRINGIZE(bubble_sort_optimized)),
        std::make_pair(heap_sort<TYPE>,                 STRINGIZE(heap_sort)),
        std::make_pair(insertion_sort<TYPE>,            STRINGIZE(insertion_sort)),
        std::make_pair(quick_sort<TYPE>,                STRINGIZE(quick_sort)),
        std::make_pair(bucket_sort<TYPE>,               STRINGIZE(bucket_sort)),
        std::make_pair(shell_sort<TYPE>,                STRINGIZE(shell_sort)),
    };

    auto sorting_result = benchmark_sorting_list(sorting_list, BENCH_NUMBER);

    for (auto const& [key, val] : sorting_result) {
        std::cout<< "sorting algorithm: "<< (val.first) << " \n\telapsed time:\t " << (val.second / BENCH_NUMBER) << " ms" << std::endl;
    }

    return 0;
}