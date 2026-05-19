You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0

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
            long long take = prices[i] + solve(i+2,1,prices,dp);
            long long leave = 0 + solve(i+1,0,prices,dp);
            profit = max(take,leave);
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+2,vector<int>(2,0));

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
                long long take = prices[i] + dp[i+2][1];
                long long leave = 0 + dp[i+1][0];
                profit = max(take,leave);
            }

            dp[i][buy] = profit;
        }
        }

        return dp[0][1];
        
    }
};
