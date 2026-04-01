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

    int postorder(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return max(postorder(node->left), postorder(node->right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        int result = postorder(root);
        return result;
    }
};
