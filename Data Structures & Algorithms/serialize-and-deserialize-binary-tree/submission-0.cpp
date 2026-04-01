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

class Codec {
public:
    void preorderSerialize(TreeNode* node, string& res) {
        if (!node) {
            res += "N,";
            return;
        }
        res += to_string(node->val) + ',';
        preorderSerialize(node->left, res);
        preorderSerialize(node->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preorderSerialize(root, res);
        res.pop_back();
        return res;
    }

    TreeNode* preorderDeSerialize(vector<string> data, int& i) {
        if (data[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(data[i]));
        i++;
        node->left = preorderDeSerialize(data, i);
        node->right = preorderDeSerialize(data, i);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        vector<string> res;
        while (getline(ss,token,',')) {
            res.push_back(token);
        }
        int i = 0;
        return preorderDeSerialize(res, i);
    }
};
