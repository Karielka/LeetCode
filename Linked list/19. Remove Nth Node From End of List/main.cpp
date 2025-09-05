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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;
        std::vector<ListNode *> pointers(32, nullptr);
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* lIter = dummyHead;
        int i = 0;
        while (lIter) {
            pointers[i++] = lIter;
            lIter = lIter->next;
        }
        pointers[i-n-1]->next = pointers[i-n+1];
        return dummyHead->next;
    }
};