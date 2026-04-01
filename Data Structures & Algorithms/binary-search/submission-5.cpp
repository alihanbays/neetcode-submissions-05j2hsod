class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m = (r + l) / 2;

        while (l <= r) {
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }

            m = (l + r) / 2;
        }
        return -1;
    }
};
