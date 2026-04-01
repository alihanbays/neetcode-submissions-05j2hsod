class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = -INT_MAX;
        int l {0};
        int r {0};
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            max_sum = max(max_sum, sum);

            if (sum < 0) {
                l = r + 1;
                r++;
                sum = 0;
            } else {
                r++;
            }
        }
        return max_sum;
    }
};
