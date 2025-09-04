#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            dict[nums[i]]++;
        }
        int mx = 0, maj = 0;
        for (const auto& [k, v] : dict) {
            if (mx < v) {
                mx = v;
                maj = k;
            }
        }
        return maj;
    }
};