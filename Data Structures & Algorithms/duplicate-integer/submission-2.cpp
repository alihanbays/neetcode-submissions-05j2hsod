class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = 1; j < i; j++) {
        //         if (nums[i] == nums[j]) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        map<int, int> checkDup = {};

        for (int i = 0; i < nums.size(); i++) {
            if (checkDup.count(nums.at(i))) {
                return true;
            }
            checkDup.insert({nums[i], 1});
        }

        return false;
    }
};