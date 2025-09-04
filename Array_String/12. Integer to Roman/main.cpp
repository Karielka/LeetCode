#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct Tuple {
    std::string sym;
    int val;         
}; 

class Solution {
    const std::array<Tuple, 13> dict;
public:
    Solution()
        :  dict{{
        {"M",1000}, {"CM",900}, {"D",500}, {"CD",400},
        {"C",100},  {"XC",90},  {"L",50},  {"XL",40},
        {"X",10},   {"IX",9},   {"V",5},   {"IV",4},
        {"I",1}
    }} {};

    std::string intToRoman(int num) {
        std::string s = "";
        for (const auto& t : dict) {
            while (num >= t.val) {
                num -= t.val;
                s += t.sym;
            }
        }
        return s;
    }
};


int main() {
    Solution pass;
    std::cout << pass.intToRoman(3);
}