class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> b(nums.size());
        std::unordered_map<int, int> um;

        for (auto num : nums) {
            if (um.count(num)) {
                um[num] += 1;
            } else {
                um[num] = 1;
            }
        }

        for (auto kv : um) {
            b[kv.second - 1].push_back(kv.first);
        }

        vector<int> res;

        for (int i = b.size() - 1; i >= 0; i--) {
            cout << to_string(i) << endl;
            if (b[i].size() != 0) {
                for (int num : b[i]) {
                    if (res.size() == k) {
                        break;
                    }

                    res.push_back(num);
                }
            }
        }

        return res;        
    }
};
