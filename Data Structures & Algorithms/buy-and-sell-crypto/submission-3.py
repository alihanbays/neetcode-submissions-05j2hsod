class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        profit = 0
        L, R = 0, 1

        while R < len(prices):
            if prices[L] < prices[R]:
                profit = max(profit, prices[R] - prices[L])
            else:
                L = R
            R += 1
        
        return profit