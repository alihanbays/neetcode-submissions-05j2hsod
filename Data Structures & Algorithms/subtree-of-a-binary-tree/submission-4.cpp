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
    bool areSameTree(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) {
            return true;
        } else if(!node1 || !node2) {
            return false;
        }

        bool leftEqual = areSameTree(node1->left, node2->left);
        bool rightEqual = areSameTree(node1->right, node2->right);
        if (node1->val == node2->val && leftEqual && rightEqual) {
            return true;
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        bool current = areSameTree(root, subRoot);
        return current || right || left;
    }
};
