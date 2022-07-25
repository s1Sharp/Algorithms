#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <utility>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;
        result.reserve(n);

        for (int i = 1; i <= n; i++) {
            result.push_back(std::string(
                (i%3==0 && i%5==0) ? "FizzBuzz":
                (i%3==0) ?           "Fizz" :
                (i%5==0) ?           "Buzz" :
                                     std::to_string(i)
                )
            );
        }
        return result;
    }

    template <typename _T1, typename _T2>
    std::vector<std::pair<_T1, _T2>> zip(std::vector<_T1> v1 , std::vector<_T2> v2) {
        size_t len = std::min(v1.size(), v2.size());
        std::vector<std::pair<_T1, _T2>>  result; result.reserve(len);
        for (size_t i = 0; i < len; i++) {
            result.push_back(std::make_pair(static_cast<_T1>(v1[i]), 
                                            static_cast<_T2>(v2[i]))
                                            );
        }
        return result;
    }
    
    void test()
    {
        // check 1
        std::vector<std::string> assertResult1 = {"1","2","Fizz"};
        auto v1 = fizzBuzz(3);
        auto pairs1 = zip<std::string, std::string>(v1, assertResult1);
        for (auto& elem: pairs1) {
            std::cout << "firts: " << elem.first << "\t\t|  second: " << elem.second << std::endl;
            assert (elem.first == elem.second);
        }

        // check 2
        std::vector<std::string> assertResult2 = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
        auto v2 = fizzBuzz(15);
        auto pairs2 = zip<std::string, std::string>(v2, assertResult2);
        for (auto& elem: pairs2) {
            std::cout << "firts: " << elem.first << "  |  second: " << elem.second << std::endl;
            assert (elem.first == elem.second);
        }
    }
};