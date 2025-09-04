#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int len = (int)nums.size();
        if (len < 2) return 0;

        int jumps = 0;
        int curEnd = 0;     // граница текущего "уровня"
        int farthest = 0;   // самая дальняя точка, достижимая из текущего окна

        for (int i = 0; i < len - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == curEnd) {     // окончилось текущее окно — делаем прыжок
                ++jumps;
                curEnd = farthest;
                if (curEnd >= len - 1) break;
            }
        }
        return jumps;
    }
};


int main() {
    Solution pass;
    std::vector<int> vect = {2,3,1,1,4};
    std::cout << pass.jump(vect);
}