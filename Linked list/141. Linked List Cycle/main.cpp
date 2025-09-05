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
    bool hasCycle(ListNode *head) {
        // std::vector<ListNode *> pointers; Создать массив указателей + find // hashTable
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1 != nullptr) {
            p1 = p1->next;
            if (p2 == nullptr || p2->next == nullptr) {break;}
            p2 = p2->next->next;
            if (p1 == p2) return true;
        }
        return false;
    }
};
