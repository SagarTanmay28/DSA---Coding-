// Recursion + Memoization 
class Solution {
  public:
    int solve(int i, vector<int>& val, vector<int>& wt, int W, vector<vector<int>> &dp){
        int n = val.size();
        
        if(i == val.size() || W <= 0) return 0;
        
        if(dp[i][W] != -1) return dp[i][W];
        
        int take = 0;
        if(wt[i] <= W){
            take = val[i] + solve(i,val,wt,W-wt[i],dp);
        }
        
        int leave = solve(i+1,val,wt,W,dp);
        
        return dp[i][W] = max(take,leave);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n = val.size();
        
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        
        return solve(0,val,wt,W,dp);
        
    }
};

// Bottom Up 
class Solution {
  public:
    
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        // code here
        int n = val.size();
        
        int dp[n+1][W+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
        
    }
};
