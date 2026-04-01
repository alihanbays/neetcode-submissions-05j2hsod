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
    int dfs(TreeNode* node, int& count, int k) {
        if (!node) {
            return -1;
        }
        
        int leftres = dfs(node->left, count, k);
        count++;
        if (count == k) {
            return node->val;
        }
        int rightres = dfs(node->right, count, k);
        
        return max(leftres, rightres);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return dfs(root, count, k);
    }
};
