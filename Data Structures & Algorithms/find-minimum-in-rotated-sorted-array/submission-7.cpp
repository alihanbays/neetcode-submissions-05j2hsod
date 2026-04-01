class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m = (r + l) / 2;
        while (l <= r) {
            if (nums[m] == nums[r]) {
                return nums[r];
            } else if (nums[m] > nums[r]) {
                l = m + 1;
            } else { 
                r = m;
            }
            m = (r + l) / 2;
        }
        return -1;
    }
};
