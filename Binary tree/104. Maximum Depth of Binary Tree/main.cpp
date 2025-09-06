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