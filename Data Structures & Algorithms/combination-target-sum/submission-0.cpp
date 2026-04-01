class Solution {
public:

    void helper(int i, vector<int>& nums, vector<vector<int>>& subset, vector<int> currentset, int target) {
        if (i >= nums.size()) {
            return;
        }
        int sum = 0;
        for (int& num : currentset) {
            sum += num;
        }

        if (sum == target) {
            subset.push_back(currentset);
            return;
        }

        if (sum > target) {
            currentset.pop_back();
            return;
        }

        currentset.push_back(nums[i]);
        helper(i, nums, subset, currentset, target);
        currentset.pop_back();

        helper(i + 1, nums, subset, currentset, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> currentset;
        vector<vector<int>> subset;
        helper(0, nums, subset, currentset, target);
        return subset;
    }
};
