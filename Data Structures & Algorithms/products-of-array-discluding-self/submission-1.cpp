class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute force approach O(n^2) time complexity o(n) space
        // vector<int> result;
        // for (int i = 0; i < nums.size(); i++) {
        //     int product = 1;
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (j != i) {
        //             product *= nums[j];
        //         }
        //     }
        //     result.push_back(product);
        // }
        // return result;
        // This approach wont be viable because we are asked to do in O(n) time
        
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result(nums.size());
        int size = nums.size();

        int product = 1;
        for (int i = 0; i < size; i++) {
            prefix[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int i = size - 1; i >= 0; i--) {
            suffix[i] = product;
            result[i] = suffix[i] * prefix[i];
            product *= nums[i];
        }

        return result;
    }
};
