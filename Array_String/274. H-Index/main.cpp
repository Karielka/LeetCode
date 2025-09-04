#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int len = (int)citations.size();
        std::vector<int> cnt(len + 1);
        for (int c : citations) {
            if (c >= len) 
                cnt[len]++;   // всё, что >= n, складываем в корзину n
            else        
                cnt[c]++;
        }

        int papers = 0;
        for (int h = len; h >= 0; --h) {
            papers += cnt[h];       // сколько статей с ≥ h цитирований
            if (papers >= h) return h;
        }
        return 0;
    }
};


int main() {
    Solution pass;
    std::vector<int> vect = {3,0,6,1,5};
    std::cout << pass.hIndex(vect);
}