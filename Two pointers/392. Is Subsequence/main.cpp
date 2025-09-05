#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int pos1 = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[pos1]) {
                pos1++;
            }
        }
        std::cout << pos1 << std::endl;
        return bool(pos1 == s.length());
    }
};

int main() {
    Solution pass;
    std::cout << pass.isSubsequence("abc", "ahbgdc");
}