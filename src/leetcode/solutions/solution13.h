#include <string>
#include <iostream>
#include <stack>
#include <assert.h>


class Solution {
public:
    int romanToInt(std::string s) {
        int prev {0}, curr {0};
        int value {0};
        for (auto c: s) {
            switch(c)
            {
                case 'I':
                    curr = 1;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
                case 'V':
                    curr = 5;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
                case 'X':
                    curr = 10;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
                case 'L':
                    curr = 50;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
                case 'C':
                    curr = 100;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
                case 'D':
                    curr = 500;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
                case 'M':
                    curr = 1000;
                    if (prev < curr) {
                        curr -= prev + prev;
                    }
                    value += curr;
                    prev = curr;
                    break;
            }
        }
        return value;
    }


    void test() {
        std::cout << romanToInt(std::string {"LVIII"}) << std::endl;
        std::cout << romanToInt(std::string {"MCMXCIV"}) << std::endl;
        assert (romanToInt(std::string {"LVIII"}) == 58);
        assert (romanToInt(std::string {"MCMXCIV"}) == 1994);
    }
};