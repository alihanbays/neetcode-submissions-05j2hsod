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
    int calculateDepth(TreeNode* node, int height) {
        if (!node) {
            return height;
        }

        // left calc
        int leftHeight = calculateDepth(node->left, height + 1);
        // right calc
        int rightHeight = calculateDepth(node->right, height + 1);
        return max(leftHeight,rightHeight);
    }

    int maxDepth(TreeNode* root) {
        return calculateDepth(root, 0);
    }
};
