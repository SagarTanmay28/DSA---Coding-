You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Recursion + Memoization 
class Solution {
public:
    long long solve(long long i, long long buy, long long cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        long long n = prices.size();

        if(i >= n || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        long long profit = 0;

        if(buy == 1){
            long long take = -prices[i] + solve(i+1,0,cap,prices,dp);
            long long leave = 0 + solve(i+1,1,cap,prices,dp);
            profit = max(take,leave);
        }
        else{
            long long take = prices[i] + solve(i+1,1,cap-1,prices,dp);
            long long leave = 0 + solve(i+1,0,cap,prices,dp);
            profit = max(take,leave);
        }

        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0,1,2,prices,dp);
    }
};

// Bottomu Up 

int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {  // cap = 0 -> runtime error 

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
        return dp[0][1][2];
}
