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
    TreeNode* postOrder(TreeNode* node, TreeNode* b, TreeNode* s) {
        if (!node) {
            return nullptr;
        }
        TreeNode* result;
        if (node->val > b->val && node->val > s->val) {
            result = postOrder(node->left, b, s);
        } else {
            result = postOrder(node->right, b, s);
        }
        // Am I less then or equal to bigger value and bigger or equal to smaller value
        if (node->val >= s->val && node->val <= b->val) {
            return node;
        }
        return result;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        if (p->val > q->val) {
            result = postOrder(root, p, q);
        } else {
            result = postOrder(root, q, p);
        }
        return result;
    }
};
