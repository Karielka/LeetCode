#include "0.h"

// 226. Invert Binary Tree

class Solution {
public:
    void descent(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        descent(root->left);
        descent(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        descent(root);
        return root;
    }
};