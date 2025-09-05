#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// + Simple solve with extra ListNode

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        //Вместо того, чтобы двигать голову, добавим в начало дополнительный элемент
        ListNode* dummyHead = new ListNode(head->val-1);
        dummyHead->next = head;
        head = dummyHead;

        ListNode* lIter = head;
        ListNode* temp;
        ListNode* cur;
        int equal;
        while ((lIter->next->next != nullptr)) {
            std::cout << lIter->val << " ";
            // Усовершенствовать удаление по while через привязку
            equal = lIter->next->val;
            if (equal == lIter->next->next->val) {
                temp = lIter->next;
                while (temp->val == equal) {
                    cur = temp->next;
                    delete temp;
                    temp = cur;
                    if (temp == nullptr) break;
                }
                lIter->next = temp;
            }
            else {
                lIter = lIter->next;
            }
            if (lIter == nullptr) {
                break;
            }
            if (lIter->next == nullptr) {
                break;
            }
        }
        // Delete dummyHead
        temp = head->next;
        delete head;
        head = temp;
    
        return head;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        ListNode *cur=head;
        while(cur!=NULL)
        {
            if (cur->next && cur->val==cur->next->val){
                while(cur->next && cur->val==cur->next->val)
                cur=cur->next;
                prev->next=cur->next;
            }
            else{
                prev=prev->next;
            }
            cur=cur->next;
        }
        return dummy->next;
    }
};