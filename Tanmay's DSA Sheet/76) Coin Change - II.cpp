You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(amount < 0 || i >= coins.size()) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = solve(amount-coins[i],coins,i,dp);
        int leave = solve(amount,coins,i+1,dp);

        return dp[i][amount] = take + leave;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};
