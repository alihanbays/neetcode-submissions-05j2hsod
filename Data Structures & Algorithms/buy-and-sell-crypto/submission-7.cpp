class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int profit = 0;
        int max_profit = 0;
        int min_profit = 0;
        while (r < prices.size()) {
            profit = prices[r] - prices[l];

            if (profit >= 0) {
                max_profit = max(max_profit, profit);
            } else {
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};
