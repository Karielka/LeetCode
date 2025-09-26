#include "0.h"

// 100. Same Tree
class Solution {
public:
    bool descent(TreeNode* p, TreeNode* q) {
        if ((p && q && (p->val != q->val)) || ((p == nullptr) xor (q == nullptr)) ) {
            return false;
        }
        if ((p == nullptr) && (q == nullptr)) {
            return true;
        }
        return descent(p->left, q->left) && descent(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return descent(p, q);
    }
};
