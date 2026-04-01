class Solution 
{
public:
    int num_houses;
    // Now adding memoization
    unordered_map<int, int> um;

    int dfs(vector<int>& nums, int house_num)
    {
        if (house_num >= num_houses)
            return 0;
        if (um.find(house_num) != um.end()) 
            return um[house_num];
        um[house_num] = max(dfs(nums, house_num + 1), dfs(nums, house_num + 2) + nums[house_num]);
        return um[house_num];
    }

    int rob(vector<int>& nums) 
    {
        num_houses = nums.size();
        return dfs(nums, 0);
    }
};
