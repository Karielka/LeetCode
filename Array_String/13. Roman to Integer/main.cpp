#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Solution {
    std::map<char, int> dict;
public:
    Solution()
        : dict{ {'I',1}, {'V',5}, {'X',10}, {'L',50},
                {'C',100}, {'D',500}, {'M',1000} } {}

    int romanToInt(std::string s) {
        int chislo = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (dict[s[i]] < dict[s[i + 1]]) {
                chislo -= dict[s[i]];
            }
            else {
                chislo += dict[s[i]];
            }
        }
        return chislo + dict[s[s.length()-1]];
    }
};


int main() {
    Solution pass;
    std::cout << pass.romanToInt("MCMXCIV");
}