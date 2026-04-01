class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;

    bool dfs(int crs) {
        if (visited.count(crs)) return false;
        if (preMap[crs].empty()) return true;

        visited.insert(crs);

        for (int i = 0; i < preMap[crs].size(); i++) {
            if (!dfs(preMap[crs][i])) return false;
        }

        visited.erase(crs);
        preMap[crs].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& preReq : prerequisites) {
            preMap[preReq[0]].push_back(preReq[1]);
        }

        for (int crs = 0; crs < numCourses; crs++) {
            if (!dfs(crs)) return false;
        }

        return true;
    }
};
