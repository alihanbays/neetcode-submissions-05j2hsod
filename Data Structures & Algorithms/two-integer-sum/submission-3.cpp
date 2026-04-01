class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hashMap;
        vector<int> result = {};
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            hashMap[difference] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.count(nums[i]) && i != hashMap[nums[i]]) {
                if (i < hashMap[nums[i]]) {
                    result.push_back(i);
                    result.push_back(hashMap[nums[i]]);
                } else {
                    result.push_back(hashMap[nums[i]]);     
                    result.push_back(i);
                }
                return result;
            }
        }
        return result;
    }
};
