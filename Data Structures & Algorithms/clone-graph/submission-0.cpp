/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node) {
        std::stack<Node*> s;
        std::unordered_map<Node*, Node*> um;

        // Create a copy of the head
        Node* copy = new Node(node->val);
        um.insert({node, copy});
        s.push(node);

        while (!s.empty()) {
            Node* tmp = s.top();
            s.pop();

            for (int i = 0; i < tmp->neighbors.size(); i++) {
                if (um.find(tmp->neighbors[i]) == um.end()) { // Its not on the map create it
                    Node* newNode = new Node(tmp->neighbors[i]->val);
                    um[tmp]->neighbors.push_back(newNode);
                    um.insert({tmp->neighbors[i], newNode});
                    s.push(tmp->neighbors[i]);
                } else {
                    um[tmp]->neighbors.push_back(um[tmp->neighbors[i]]);
                }
            }
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};
