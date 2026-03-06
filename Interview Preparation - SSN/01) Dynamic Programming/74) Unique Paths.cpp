class Solution { // Recursion + Memoization
public:
    int paths(int m, int n, vector<vector<int>>& dp){
        if(m==1 && n==1) return 1;
        if(m==0 || n==0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int rightWays = paths(m,n-1,dp);
        int downWays = paths(m-1,n,dp);
        return dp[m][n] = rightWays + downWays;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return paths(m,n,dp);
        
    }
};
