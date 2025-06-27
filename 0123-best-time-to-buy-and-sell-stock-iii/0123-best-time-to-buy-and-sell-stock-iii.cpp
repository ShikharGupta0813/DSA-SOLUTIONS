class Solution {
public:
    int f(vector<int>& prices, int i, int opt, vector<vector<int>>& dp,int cap) {
        if (i == prices.size()) return 0;
        if(cap==0)return 0;
        if (dp[i][opt] != -1) return dp[i][opt];

        if (opt == 1) {
            // Buy or skip
            return dp[i][opt] = max(-prices[i] + f(prices, i + 1, 0, dp,cap),
                                     0 + f(prices, i + 1, 1, dp,cap));
        } else {
            // Sell or skip
            return dp[i][opt] = max(prices[i] + f(prices, i + 1, 1, dp,cap-1),
                                     0 + f(prices, i + 1, 0, dp,cap));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 1, dp,2);  // Start from day 0 with buy option
    }
};