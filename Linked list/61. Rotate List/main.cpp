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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        std::vector<ListNode *> pointers(500, nullptr);
        ListNode* lIter = head;
        int i = 0;
        while (lIter) {
            pointers[i++] = lIter;
            lIter = lIter->next;
        }
        int sdvig = k % i;
        if (sdvig == 0) return head;
        std::cout << "i = " << i << "; sdvig = " << sdvig << std::endl;
        ListNode* newHead = pointers[i-sdvig];
        std::cout << "newHead_val = " << newHead->val << std::endl;
        pointers[i-1]->next = head;
        pointers[i-sdvig-1]->next = nullptr;
        
        return newHead;
    }
};