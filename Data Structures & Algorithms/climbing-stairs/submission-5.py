class Solution:
    def climbStairs(self, n: int) -> int:

        # recursion steps +1 or +2
        # on top of our staircase is "n" that means thats our limit
        cache = n * [-1]

        def dp(i: int) -> int:
            # did I go above my limit
            if (i > n):
                return 0 # 0 meaning this is not a valid path
            if (i == n):
                return 1 # 1 way

            if (cache[i] != -1):
                return cache[i]
            
            cache[i] = dp(i + 1) + dp(i + 2)
            return cache[i]

        return dp(0)
        