#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int len = (int)nums.size();
        if (len < 2) {
            return len;
        }
        std::vector<int> nums1;
        nums1.reserve(len);
        // nums1[0] = nums[0];
        // nums1[1] = nums[1];
        nums1.push_back(nums[0]);
        nums1.push_back(nums[1]);
        int pos = 2;
        for (int i = 2; i < len; i++) {
            if (nums[i] != nums[i-2]) {
                // nums1[pos] = nums[i];
                nums1.push_back(nums[i]);
                pos++;
            }
        }
        nums1.resize(pos);
        nums = std::move(nums1);
        return (nums.size());
    }
};

static void print_vec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    Solution pass;
    std::vector<int> vec = {1,1,1,2,2,3};
    pass.removeDuplicates(vec);
    print_vec(vec);
}