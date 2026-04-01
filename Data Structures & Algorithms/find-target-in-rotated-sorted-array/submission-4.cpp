class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // Is my mid on left portion or right portion.
            if (nums[l] <= nums[mid]) {
                // I am on the left portion.

                // Is target in the left portion?
                if (target < nums[mid] && target >= nums[l]) {
                    // Target is on the left portion.
                    // Eliminate right portion.
                    r = mid - 1;
                } else {
                    // Target is in the right portion.
                    l = mid + 1;
                }
            } else {
                // I am on the right portion.
                if (target > nums[mid] && target <= nums[r]) {
                    // Target is on my right portion;
                    // Eliminate the left portion;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
