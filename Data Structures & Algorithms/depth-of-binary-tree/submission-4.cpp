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

    int postorder(TreeNode* node, int height) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = postorder(node->left, height + 1);
        int rightDepth = postorder(node->right, height + 1);

        return std::max(leftDepth, rightDepth) + 1;

    }
    int maxDepth(TreeNode* root) {
        int height = 0;
        return postorder(root, height);
    }
};
