#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int i = 0; i < n; ++i) nums1[i] = nums2[i];
            return;
        }

        std::vector<int> nums(m+n);
        int pos = 0, pos1 = 0, pos2 = 0;
        
        // пока в обоих массивах есть элементы — кладём меньший
        while (pos1 < m && pos2 < n) {
            if (nums1[pos1] <= nums2[pos2]) {
                nums[pos++] = nums1[pos1++];
            } else {
                nums[pos++] = nums2[pos2++];
            }
        }
        // В одном массиве уже нет элементов, поэтому дорабатывает единственный while
        while (pos1 < m) nums[pos++] = nums1[pos1++];
        while (pos2 < n) nums[pos++] = nums2[pos2++];

        nums1 = std::move(nums);
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

static void run_test(const std::string& name,
                     std::vector<int> nums1, int m,
                     std::vector<int> nums2, int n,
                     const std::vector<int>& expected)
{
    Solution s;
    s.merge(nums1, m, nums2, n);

    bool ok = (nums1 == expected);
    std::cout << (ok ? "PASS " : "FAIL ") << name << " -> got ";
    print_vec(nums1);
    std::cout << " | expected ";
    print_vec(expected);
    std::cout << std::endl;
}

int main() {
    // Example 1
    run_test("ex1",
             /*nums1*/ {1,2,3,0,0,0}, /*m*/ 3,
             /*nums2*/ {2,5,6},       /*n*/ 3,
             /*expected*/ {1,2,2,3,5,6});

    // Example 2
    run_test("ex2",
             /*nums1*/ {1},  /*m*/ 1,
             /*nums2*/ {},   /*n*/ 0,
             /*expected*/ {1});

    // Example 3
    run_test("ex3",
             /*nums1*/ {0},  /*m*/ 0,
             /*nums2*/ {1},  /*n*/ 1,
             /*expected*/ {1});

    return 0;
}