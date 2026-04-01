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
    bool isSameChild(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        } else if (!t1 || !t2) {
            return false;
        }

        bool isLeftEqual = isSameChild(t1->left, t2->left);
        bool isRightEqual = isSameChild(t1->right, t2->right);
        cout << t1->val << endl;
        cout << t2->val << endl;

        if (t1->val == t2->val && isLeftEqual && isRightEqual) {
            return true;
        } else {
            return false;
        }
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameChild(p, q);
    }
};
