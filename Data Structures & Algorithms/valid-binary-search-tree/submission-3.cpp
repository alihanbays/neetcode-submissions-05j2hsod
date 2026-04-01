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
    bool preorder(TreeNode* node, pair<int,int> limits) {
        if (!node) {
            return true;
        }
        if (limits.first >= node->val || limits.second <= node->val || limits.first >= limits.second) {
            return false;
        }
        bool leftBST = preorder(node->left, pair<int,int> {limits.first, node->val});
        bool rightBST = preorder(node->right, pair<int,int> {node->val, limits.second});
        
        return leftBST && rightBST;
    }

    bool isValidBST(TreeNode* root) {
        return preorder(root, pair<int, int>{-INT_MAX, INT_MAX});
    }
};
