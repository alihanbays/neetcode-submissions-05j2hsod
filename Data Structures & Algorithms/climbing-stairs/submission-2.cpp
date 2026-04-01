class Solution 
{
public:
    unordered_map<int, int> um;

    int memoization(int target, int current)
    {
        if (target == current)     
            return 1;
        if (um.find(current) != um.end())
            return um[current];
        if (current > target) {
            um[current] = 0;
            return 0;
        }

        um[current] = memoization(target, current + 1) + memoization(target, current + 2);
        return um[current];
    }

    int climbStairs(int n) 
    {
        return memoization(n, 0);
    }
};
