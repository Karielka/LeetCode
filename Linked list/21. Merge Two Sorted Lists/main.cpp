struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void addItem(ListNode* l1Iter, ListNode* l2Iter, ListNode* newEl) {
        if ((l1Iter != nullptr || l2Iter != nullptr)) {
            ListNode* next = new ListNode();
            newEl->next = next;
            newEl = next;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* list = new ListNode();
        ListNode* newEl = list;
        ListNode* l1Iter = list1;
        ListNode* l2Iter = list2;
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
        while (l1Iter != nullptr) {
            newEl->val = l1Iter->val;
            l1Iter = l1Iter->next;
            if ((l1Iter != nullptr || l2Iter != nullptr)) {
                ListNode* next = new ListNode();
                newEl->next = next;
                newEl = next;
            }
        }
        while (l2Iter != nullptr) {
            newEl->val = l2Iter->val;
            l2Iter = l2Iter->next;
            if (l2Iter != nullptr) {
                ListNode* next = new ListNode();
                newEl->next = next;
                newEl = next;
            }
        }
        return list;
    }
};