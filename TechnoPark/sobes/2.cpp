// 141. Linked List Cycle

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
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *l1Iter = head, *l2Iter = head;
        while (l1Iter != nullptr) {
            l1Iter = l1Iter->next;
            if (l2Iter == nullptr || l2Iter->next == nullptr) {break;}
            l2Iter = l2Iter->next->next;
            if (l1Iter == l2Iter) return true;
        }
        return false;
    }
};
