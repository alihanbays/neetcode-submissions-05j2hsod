class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& um, unordered_set<int>& visited, int node) {
        if (visited.find(node) != visited.end()) return false;
        if (um[node].empty()) return true;

        visited.insert(node);

        for (int i = 0; i < um[node].size(); i++) {
            if (!dfs(um, visited, um[node][i])) return false;
        }

        visited.erase(node);
        um[node].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> um;
        unordered_set<int> visited;

        for (int i = 0; i < prerequisites.size(); i++) {
            int node = prerequisites[i][0];
            int neighbor = prerequisites[i][1];

            if (node == neighbor) return false;

            if (um.find(node) == um.end()) {
                um[node] = {neighbor};
            } else {
                um[node].push_back(neighbor);
            }
        }

        if (prerequisites.size() == 0) return true;

        for (auto it = um.begin(); it != um.end(); ++it) {
            if (!dfs(um, visited, it->first)) return false;
        }
        return true;
    }
};
