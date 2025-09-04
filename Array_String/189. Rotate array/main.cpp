#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int len = int(nums.size());
        int temp = k % (len);
        std::vector<int> vect(len);
        vect.reserve(len);
        for (int i = 0; i < temp; i++) {
            vect[i] = nums[len - temp + i];
        }
        for (int i = temp; i < len; i++) {
            vect[i] = nums[i-temp];
        }
        nums = std::move(vect);
    }
};