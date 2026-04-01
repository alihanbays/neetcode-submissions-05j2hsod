class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> um;

        for (int num : nums) {
            if (um.count(num)) {
                um[num] += 1;
            } else {
                um[num] = 1;
            }
        }

        vector<pair<int, int>> vp;

        for (auto kp : um) {
            vp.push_back(make_pair(kp.first, kp.second));
        }

        std::sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int ,int> b) {
            return a.second > b.second;
        });

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(vp[i].first);
        }
        return res;
    }
};
