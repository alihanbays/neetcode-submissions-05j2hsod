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

    bool isSubSet(std::vector<int> &haystack, std::vector<int> &needle) {
        if (needle.empty()) {
            return true;
        } else if (needle.size() > haystack.size()) {
            return false;
        }

        const auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end());

        if (it == haystack.end()) {
            return false;
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::vector<int> l1, l2;
        preorder(root, l1);
        preorder(subRoot, l2);

        std::cout << "L1: ";
        for (auto it = l1.begin(); it != l1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "L2: ";
        for (auto it = l2.begin(); it != l2.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        return isSubSet(l1, l2);
    }
};
