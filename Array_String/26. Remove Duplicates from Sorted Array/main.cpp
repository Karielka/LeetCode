#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::vector<int> nums1(nums.size());
        nums1[0] = nums[0];
        int del_count = 0, pos = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                del_count++;
            }
            else {
                nums1[pos] = nums[i];
                pos++;
            }
        }
        for (int i = 0; i < del_count; i++, pos++) {
            nums1[pos] = 0;
        }
        nums = std::move(nums1);
        return (nums.size() - del_count);
    }
};