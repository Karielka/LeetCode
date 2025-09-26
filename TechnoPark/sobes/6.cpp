#include <0.h>

// 101. Symmetric Tree

class Solution {
public:
    bool descent(TreeNode* p, TreeNode* q) {
        if ((p && q && (p->val != q->val)) || ((p == nullptr) xor (q == nullptr)) ) {
            return false;
        }
        if ((p == nullptr) && (q == nullptr)) {
            return true;
        }
        return descent(p->left, q->right) && descent(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return descent(root->left, root->right);
    }
};
