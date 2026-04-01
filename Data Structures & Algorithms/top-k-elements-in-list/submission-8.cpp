class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> b(nums.size() + 1);
        std::unordered_map<int, int> um;

        for (int num : nums) {
            um[num] = 1 + um[num];
        }

        for (const auto& kv : um) {
            b[kv.second].push_back(kv.first);
        }

        vector<int> res;
        for (int i = b.size() - 1; i > 0; --i) {
            for (int num : b[i]) {
                if (res.size() == k) { 
                    return res;
                }
                res.push_back(num);
            }
        }
        return res;        
    }
};
