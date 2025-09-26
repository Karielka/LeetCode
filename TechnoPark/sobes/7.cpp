#include <0.h>

// 112. Path Sum

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; 
        if (!root->left && !root->right) return (root->val == targetSum);
        bool leftSum = hasPathSum(root->left, targetSum - root->val);
        bool rightSum = hasPathSum(root->right, targetSum - root->val);
        return leftSum || rightSum;
    }
};