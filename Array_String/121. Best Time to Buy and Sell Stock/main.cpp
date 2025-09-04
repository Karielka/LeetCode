#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = prices[0], profit = 0, perem;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            perem = prices[i] - min_price;
            if (perem > profit) {
                profit = perem;
            }
        }
        return profit;
    }
};