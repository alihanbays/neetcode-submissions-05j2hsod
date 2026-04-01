/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr || p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    void preorder(TreeNode* node, TreeNode* subRoot, bool &found) {
        if (node == nullptr) return;
        if (isSameTree(node, subRoot)) found = true;

        preorder(node->left, subRoot, found);
        preorder(node->right, subRoot, found);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool found = false;

        preorder(root, subRoot, found);

        return found;
    }
};