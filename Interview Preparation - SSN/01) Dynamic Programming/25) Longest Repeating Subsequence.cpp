class Solution {
  public:
    int LongestRepeatingSubsequence(string &s1) {
        // Code here
        int n = s1.size();
        
        string s2 = s1;
        
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // 2D Vector 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // same 
                if(s1[i-1] == s2[j-1] && i != j){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                // different
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
};
