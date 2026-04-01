class Solution {
public:
    int findMin(vector<int> &nums) {
        // Assume input is: [1,2,3,4,5,6]
        // Lets assume it was rotated 4 times [3,4,5,6,1,2]

        // Lets continue with regular binary serach
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        int m = (l+r) / 2;
        if (n == 1) {
            return nums[0];
        }

        while (l <= r) {
            cout << nums[m] << endl;
            if (nums[(m-1 + n) % n] > nums[m]) {
                return nums[m];
            } else if (nums[m] > nums[l] && nums[m] > nums[r]) {
                if (nums[r] < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (nums[m] < nums[l] && nums[m] < nums[r]) {
                if (nums[r] > nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (nums[l] < nums[r]) {
                    return nums[l];
                }
                return nums[r];
            }

            m = (l+r) / 2;
        }
        return -1;
    }
};
