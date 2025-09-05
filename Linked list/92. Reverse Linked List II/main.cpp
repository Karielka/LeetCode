#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        int len = right-left+2;
        std::vector<ListNode *> pointers(len);
        ListNode* lIter = head;
        for (int i = 0; i < right; i++ ) {
            if (i >= (left-2)) {
                pointers[i-left+2] = lIter;
                std::cout << lIter->val << " ";
            }
            lIter = lIter->next;
        }
        ListNode* start;
        if (left != 1) {
            start = pointers[0];
        }
        else {
            start = pointers[len-1];
            head = start;
        }
        ListNode* next = lIter;
        for (int i = len - 1 - int(left == 1); i > 0; i--) {
            start->next = pointers[i];
            start = pointers[i];
        }
        start->next = next;
        return head;
    }
};