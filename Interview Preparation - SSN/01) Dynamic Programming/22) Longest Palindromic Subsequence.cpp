class Solution {
public:
    int helper(string& s, int i, int j, vector<vector<int>>& dp){

        if(i >= s.size() || j < 0) return 0;
        if(i == j) return 1;
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] =  2 + helper(s,i+1,j-1,dp);
        else return dp[i][j] = max(helper(s,i+1,j,dp),helper(s,i,j-1,dp));
        
    }
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        
        string s2 = s1;
        reverse(s2.begin(),s2.end()); // reverse
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // 2D Vector 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // same 
                if(s1[i-1] == s2[j-1]){
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
