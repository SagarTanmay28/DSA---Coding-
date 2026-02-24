You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

// Recursion + Memoization 
class Solution {
public:
    long long solve(long long i, long long buy, vector<int>& prices, vector<vector<int>>& dp){
        long long n = prices.size();
        long long profit = 0;

        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            long long take = -prices[i] + solve(i+1,0,prices,dp);
            long long leave = 0 + solve(i+1,1,prices,dp);
            profit = max(take,leave);
        }
        else{
            long long take = prices[i] + solve(i+1,1,prices,dp);
            long long leave = 0 + solve(i+1,0,prices,dp);
            profit = max(take,leave);
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(0,1,prices,dp);
        
    }
};

// Bottom Up 
int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        dp[n][0] = dp[n][1] = 0;

        // Top - Down -> 0 to n
        // Bottom UP  -> n-1 to 0

        long long profit = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                if(buy){
                long long take = -prices[i] + dp[i+1][0];
                long long leave = 0 + dp[i+1][1];
                profit = max(take,leave);
            }
        else{
                long long take = prices[i] + dp[i+1][1];
                long long leave = 0 + dp[i+1][0];
                profit = max(take,leave);
            }

            dp[i][buy] = profit;
        }
        }

        return dp[0][1];
        
    }
