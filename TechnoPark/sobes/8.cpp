#include <0.h>

//222. Count Complete Tree Nodes

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        else return countNodes(root->left) + countNodes(root->right) + 1; 
    }
};