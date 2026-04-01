class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet {nums[i],nums[j],nums[k]};
                        sort(triplet.begin(), triplet.end());
                        cout << triplet[0] << triplet[1] << triplet[2] << endl;
                        auto it = find(result.begin(), result.end(), triplet);
                        if (it == result.end()) {
                            result.push_back(triplet);
                        }
                    }
                }
            }
        }

        return result;
    }
};
