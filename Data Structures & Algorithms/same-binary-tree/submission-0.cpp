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

    void preorder(TreeNode* node, std::vector<int> &l) {
        if (node == nullptr) {
            l.push_back(-1);
            return;
        }

        l.push_back(node->val);
        preorder(node->left, l);
        preorder(node->right, l);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::vector<int> list1;
        std::vector<int> list2;
        preorder(p, list1);
        preorder(q, list2);

        for (auto c : list1) {
            std::cout << c << std::endl; 
        }

        for (auto c : list2) {
            std::cout << c << std::endl; 
        }
        
        return list1 == list2;
    }
};
