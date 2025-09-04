#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int> nums1;
        int del_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                del_count++;
            }
            else {
                nums1.push_back(nums[i]);
            }
        }
        for (int i = 0; i < del_count; i++) {
            nums1.push_back(0);
        }
        nums = std::move(nums1);
        return (nums.size() - del_count);
    }
};