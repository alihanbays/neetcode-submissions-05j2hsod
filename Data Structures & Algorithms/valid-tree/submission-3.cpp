class Solution {
public:
    unordered_map<int, vector<int>> um;
    unordered_set<int> visited;

    bool dfs(int node, int prevNode) {
        if (visited.count(node)) {
            cout << "node is already in visited: " << node << endl;
            return false;
        }

        //cout << "Visited: " << node << endl;
        visited.insert(node);

        if (visited.size() == um.size()) return true;

        prevNode = node;
        // Go all the neighbors
        for (int i = 0; i < um[node].size(); i++) {
            if (prevNode != um[node][i])
                if (dfs(um[node][i], prevNode))
                    return true;
        }

        // um size is the "n" total node size. If the visited size equal to it that means we visited all of it.
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false; 

        if (edges.size() == 0)
            return true;
            
        // Lets assume the root
        int root = edges[0][0];

        // Declare all the nodes and their relationships start empty
        for (int i = 0; i < n; i++) {
            um[i] = {};
        }
        
        // Add all the relationship between nodes
        for (const auto& nodes : edges) {
            um[nodes[0]].push_back(nodes[1]);
            um[nodes[1]].push_back(nodes[0]);
            //cout << nodes[0] << " -> " << nodes[1] << endl;
        }
        
        // Start DFS from root
        if (!dfs(root, -1))
            return false;

        return true;
    }
};
