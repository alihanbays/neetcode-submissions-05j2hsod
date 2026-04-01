class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> um;
        vector<vector<string>> res;

        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            um[tmp].push_back(str);
        }

        for (auto i : um) {
            res.push_back(i.second);
        }

        return res;
    }
};
