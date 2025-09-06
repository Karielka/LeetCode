#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
