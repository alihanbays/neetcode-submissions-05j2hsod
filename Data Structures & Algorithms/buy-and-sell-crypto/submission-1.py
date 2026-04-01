class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        profit = 0
        lowest = prices[0]

        for n in prices:
            if n < lowest:
                lowest = n

            profit = max(profit, n - lowest)
        
        return profit
                
        


