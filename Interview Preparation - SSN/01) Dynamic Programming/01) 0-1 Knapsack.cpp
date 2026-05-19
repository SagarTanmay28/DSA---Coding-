// Recursion + Memoization 
class Solution {
  public:
   int helper(int c, vector<int> &val, vector<int> &wt, int i, int sum, vector<vector<int>> &dp){
        if(sum > c) return INT_MIN; // invalid case
        if(i == val.size()) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take = val[i] + helper(c, val, wt, i+1, sum + wt[i], dp);
        int leave = helper(c, val, wt, i+1, sum, dp);
        
        return dp[i][sum] = max(take, leave);
    }
    
    int knapsack(int c, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(c+1, -1));
        return helper(c, val, wt, 0, 0, dp);
        
    }
};


// Recursive + Memoization 
class Solution {
  public:
    int solve(int W,vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
        if(n == 0 || W <= 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + solve(W-wt[n-1],val,wt,n-1,dp), solve(W,val,wt,n-1,dp));
        }
        else return dp[n][W] =  solve(W,val,wt,n-1,dp);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        
        return solve(W,val,wt,n,dp);
        
        
    }
};


// Bottom Up 

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        int dp[n+1][W+1];
        
        // Initialization 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        
        // Choice Diagram 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j] );
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
    }
};
