class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force
        vector<int> result = {};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (i != j && (nums[i] + nums[j]) == target) {
                    if (i < j) {
                        result.push_back(i);
                        result.push_back(j);
                    } else {
                        result.push_back(j);   
                        result.push_back(i);
                    }
                    return result;
                }
            }
        }
        return result;
    }
};
