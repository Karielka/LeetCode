// 104. Maximum Depth of Binary Tree

#include "0.h"

class Solution {
public:
    int descent(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(descent(root->left), descent(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return descent(root);
    }
};