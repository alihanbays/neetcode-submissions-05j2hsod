class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        while (r < prices.size()) {
            int profit = prices[r] - prices[l];
            if (profit <= 0) {
                l = r;
            }

            if (maxProfit < profit) {
                maxProfit = profit;
            }
            
            r++;
        }

        return maxProfit;
    }
};
