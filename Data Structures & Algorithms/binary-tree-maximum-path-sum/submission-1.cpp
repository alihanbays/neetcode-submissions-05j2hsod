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
    int res = -INT_MAX;
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        // Whats my left max
        int leftMax = dfs(node->left);
        int rightMax = dfs(node->right);

        // what if I CAN SPLIT
        int total = leftMax + rightMax + node->val;
        res = max(res, total);

        // what if I can't split
        total = max({leftMax + node->val, rightMax + node->val, node->val});
        res = max(res,total);

        return max({leftMax + node->val, rightMax + node->val, node->val});
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
