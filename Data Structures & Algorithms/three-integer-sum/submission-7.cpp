class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0) {
                if (nums[i-1] == nums[i]) {
                    continue;
                }
            }

            int target = nums[i] * -1;
            int l = i + 1;
            int r = nums.size() - 1;
            int lastLeft = 1000;
            
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (target == sum && nums[l] != lastLeft) {
                    lastLeft = nums[l];
                    vector<int> triplet {nums[i], nums[l], nums[r]};
                    result.push_back(triplet); 
                    l++;
                    r--;
                } else if (target > sum) {
                    l++;
                    // while (nums[l] == nums[l-1]) {
                    //     l++;
                    // }
                } else if (target < sum) {
                    r--;
                    // while (nums[r] == nums[r+1]) {
                    //     r--;
                    // }
                } else {
                    l++;
                    r--;
                }
            }

        }

        return result;
    }
};
