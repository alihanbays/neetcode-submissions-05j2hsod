class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }

        int jumpPower = nums[0];
        int i = 0;

        while (jumpPower > 0 && i < nums.size()) {
            jumpPower--;
            
            if (jumpPower < nums[i]) {
                jumpPower = nums[i];
            }
            
            i++;
        }

        if (i == nums.size()) {
            return true;
        } else {
            return false;
        }
    }
};
