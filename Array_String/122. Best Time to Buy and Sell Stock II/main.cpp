#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0, temp, len = prices.size();
        if (len < 2) return 0;
        for (int i = 0; i < len - 1; i++) {
            temp = prices[i + 1] - prices[i];
            if (temp > 0) {
                profit += temp;
            }
        }
        return profit;
    }
};


int main() {
    Solution pass;
    std::vector<int> vect = {7,1,5,3,6,4};
    std::cout << pass.maxProfit(vect);
}