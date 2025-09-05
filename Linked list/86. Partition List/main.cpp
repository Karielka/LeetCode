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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lIter = head; //Итератор по списку в 1 проход
        ListNode* dummyHead = new ListNode(0,head);
        ListNode* prev = nullptr; 
        ListNode* cur = dummyHead; // Указатель на конец nodes < x
        ListNode* temp; // Для перебрасывания адресов
        bool was_x = false; // Был ли x

        while (lIter) {
            std::cout << "val = " << lIter->val << std::endl;
            if (lIter && lIter->val < x) {
                if (was_x) { // переставлем элемент lIter на позицию cur->next
                    temp = lIter;
                    prev->next = lIter->next;
                    temp->next = cur->next;
                    cur->next = temp;
                    cur = cur->next;
                    lIter = prev;
                }
                else { // двигаем указатель на элементы, меньшие x
                    cur = cur->next;
                }
            }
            else {
                was_x = true;
            }

            prev = lIter;
            lIter = lIter->next;
        }
        return dummyHead->next;
    }
};


// Другое решение: создать 2 списка, в один класть < x, во второй > x, замнкуть первый на второй. За 1 проход, неэффективно по памяти

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // два фиктивных головы для списков <x и >=x
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* lt = &lessDummy;     // итератор списка < x
        ListNode* ge = &greaterDummy;  // итератор списка >= x

        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                lt->next = new ListNode(cur->val);
                lt = lt->next;
            } else {
                ge->next = new ListNode(cur->val);
                ge = ge->next;
            }
        }

        ge->next = nullptr;                // закрываем правый хвост
        lt->next = greaterDummy.next;      // склеиваем
        return lessDummy.next;             
    }
};
