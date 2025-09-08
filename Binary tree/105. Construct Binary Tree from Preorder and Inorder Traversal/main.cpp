#include <iostream>
#include <vector>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        // отладка
        // cout << "inorder = "; print_vec(inorder);
        // cout << "; preorder = "; print_vec(preorder); cout << "\n";

        if (preorder.empty()) return nullptr;

        // 1) корень — первый элемент префиксного обхода
        int rootVal = preorder[0];
        TreeNode* head = new TreeNode(rootVal);

        // 2) находим позицию корня в inorder
        auto it = std::find(inorder.begin(), inorder.end(), rootVal);
        int mid = (int)std::distance(inorder.begin(), it); // размер левого поддерева

        // 3) формируем срезы (в твоём стиле)
        // inorder: [0 .. mid-1] — left, [mid+1 .. end) — right
        std::vector<int> inLeft (inorder.begin(),        inorder.begin() + mid);
        std::vector<int> inRight(inorder.begin() + mid + 1, inorder.end());

        // preorder: [1 .. 1+mid) — left, [1+mid .. end) — right
        std::vector<int> preLeft (preorder.begin() + 1,             preorder.begin() + 1 + mid);
        std::vector<int> preRight(preorder.begin() + 1 + mid,       preorder.end());

        // 4) рекурсивно строим поддеревья
        head->left  = buildTree(preLeft, inLeft);
        head->right = buildTree(preRight, inRight);

        return head;
    }
};


#include <vector>
#include <unordered_map>

// struct TreeNode { ... } // как на LeetCode

class Solution {
    std::unordered_map<int,int> inPos;  // значение -> индекс в inorder

    // строим дерево по диапазонам:
    // preorder[pl..pr], inorder[il..ir]
    TreeNode* build(const std::vector<int>& pre, int pl, int pr,
                    const std::vector<int>& in,  int il, int ir)
    {
        if (pl > pr) return nullptr;
        int rootVal = pre[pl];
        int mid = inPos[rootVal]; // позиция корня в inorder
        int leftLen = mid - il;   // размер левого поддерева

        TreeNode* root = new TreeNode(rootVal);
        root->left  = build(pre, pl + 1, pl + leftLen, in, il, mid - 1);
        root->right = build(pre, pl + leftLen + 1, pr, in, mid + 1, ir);
        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        inPos.clear();
        inPos.reserve(inorder.size() * 2);    // меньше ре-хешей
        for (int i = 0; i < (int)inorder.size(); ++i) inPos[inorder[i]] = i;

        return build(preorder, 0, (int)preorder.size() - 1,
                     inorder,  0, (int)inorder.size()  - 1);
    }
};
