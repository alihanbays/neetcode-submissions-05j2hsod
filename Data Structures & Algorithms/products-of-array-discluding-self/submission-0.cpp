class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute force approach O(n^2) time complexity o(n) space
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    product *= nums[j];
                }
            }
            result.push_back(product);
        }
        return result;
    }
};
