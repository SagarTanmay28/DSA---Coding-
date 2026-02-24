You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


// Bottom Up 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {  // cap = 0 -> runtime error 

                    if (buy == 1) {
                        int take  = -prices[i] + dp[i + 1][0][cap];
                        int leave = dp[i + 1][1][cap];
                        dp[i][buy][cap] = max(take, leave);
                    }
                    else {
                        int take  = prices[i] + dp[i + 1][1][cap - 1];
                        int leave = dp[i + 1][0][cap];
                        dp[i][buy][cap] = max(take, leave);
                    }
                }
            }
        }

        // Start from day 0, can buy, 2 transactions
        return dp[0][1][k];
    }
};
