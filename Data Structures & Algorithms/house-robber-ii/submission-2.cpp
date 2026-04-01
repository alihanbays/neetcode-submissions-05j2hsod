class Solution 
{
public:
    unordered_map<int, int> um;

    int memoization(vector<int>& l, int start_index, int end_index)
    {
        if (start_index > end_index)
            return 0;
        if (um.find(start_index) != um.end())
            return um[start_index];

        um[start_index] = max(memoization(l, start_index + 1, end_index), memoization(l, start_index + 2, end_index) + l[start_index]);

        return um[start_index];
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int l1 = memoization(nums, 0, n - 2);
        um.clear();
        int l2 = memoization(nums, 1, n - 1);

        return max(l1, l2);
    }
};
