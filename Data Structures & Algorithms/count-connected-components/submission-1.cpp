class Solution {
public:
    unordered_map<int, vector<int>> um;
    unordered_set<int> visited;

    void dfs(int node) {
        if (visited.find(node) != visited.end()) {
            return;
        }

        visited.insert(node);

        for (int neighbor : um[node]) {
            dfs(neighbor);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int result = 0;
        // Initilize every node from n to n-1 to empty (no neighbor)
        for (int i = 0; i < n; i++) {
            um[i] = {};
        }

        // Add neighbors
        for (const vector<int> &v : edges) {
            um[v[0]].push_back(v[1]);
            um[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                result++;
            }
            dfs(i);
        }

        return result;
    }
};
