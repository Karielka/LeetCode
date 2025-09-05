#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lStart = nullptr;
        ListNode* lEnd = nullptr;
        ListNode* l1Iter = l1;
        ListNode* l2Iter = l2;
        ListNode* lNew = new ListNode();
        lStart = lNew;
        int perenos = 0, sum, sum1, val1, val2;
        while (true) {
            if (l1Iter != nullptr) { val1 = l1Iter->val; l1Iter = l1Iter->next; } else val1 = 0;
            if (l2Iter != nullptr) { val2 = l2Iter->val; l2Iter = l2Iter->next; } else val2 = 0;
            sum = lNew->val + val1 + val2;
            perenos = (sum / 10);
            lNew->val = (sum) % 10;
            std::cout << "val1 = " << val1 << " val2 = " << val2 << " ";
            std::cout << "sum = " << sum % 10 << " perenos = " << perenos << std::endl;
            if ((l1Iter != nullptr) || ((l2Iter != nullptr)) || (perenos > 0)) {
                ListNode* lNext = new ListNode(perenos);
                lNew->next = lNext;
                lNew = lNext;
            }
            else break;
        }

        return lStart;
    }
};
