// 21. Merge Two Sorted Lists
// Easy

// Topics
// premium lock icon
// Companies
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* list = new ListNode();
        ListNode *newEl = list, *l1Iter = list1, *l2Iter = list2;
        while (l1Iter != nullptr && l2Iter != nullptr) {
            if (l1Iter->val > l2Iter->val) {
                newEl->val = l2Iter->val;
                l2Iter = l2Iter->next;
            }
            else {
                newEl->val = l1Iter->val;
                l1Iter = l1Iter->next;
            }
            ListNode* next = new ListNode();
            newEl->next = next;
            newEl = next;
        }
        l1Iter = (l1Iter == nullptr) ? l2Iter : l1Iter;
        while (l1Iter != nullptr) {
            newEl->val = l1Iter->val;
            l1Iter = l1Iter->next;
            if (l1Iter != nullptr) {
                ListNode* next = new ListNode();
                newEl->next = next;
                newEl = next;
            }
        }
        return list;
    }
};