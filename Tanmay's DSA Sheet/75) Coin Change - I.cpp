You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

  


class Solution {
public:
    long long helper(vector<int>& coins, int amount, int i, long long sum, vector<vector<int>>& dp){
        if(sum == amount) return 0;
        if(sum > amount || i >= coins.size()) return INT_MAX;

        if(dp[i][sum] != -1) return dp[i][sum];

        long long take = LLONG_MAX;
        if(coins[i] <= amount){
            take = 1 +  helper(coins,amount,i,sum+coins[i],dp);
        }

        long long leave = helper(coins,amount,i+1,sum,dp);

        return dp[i][sum] = min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
 
        int ans = helper(coins,amount,0,0LL,dp);
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};
