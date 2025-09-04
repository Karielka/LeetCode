#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int supplies = 0, len = (int)nums.size();
        if (len < 2) return true;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > supplies) {
                supplies = nums[i];
            }
            supplies -= 1;
            if (supplies < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution pass;
    std::vector<int> vect = {2,3,1,1,4};
    std::cout << pass.canJump(vect);
}