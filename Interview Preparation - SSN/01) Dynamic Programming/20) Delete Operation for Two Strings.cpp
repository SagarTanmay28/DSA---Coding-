// Recursion + Memoization 
class Solution {
public:
    int LCS(string& s, string& t, int i, int j , vector<vector<int>>& dp){

        if(i >= s.size() || j >= t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] =  1 + LCS(s,t,i+1,j+1,dp);
        }
        else{
            int first = LCS(s,t,i+1,j,dp);
            int second = LCS(s,t,i,j+1,dp);
            return dp[i][j] = max(first,second);
        }
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        int length = LCS(s,t,0,0,dp);

        return (n-length) + (m-length);
        
    }
};

// Bottom Up 
class Solution {

  public:
    int minDistance(string &s1, string &s2) {
        // Your code goes here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); // 2D Vector 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
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
        
        int LCS = dp[n][m];
        
        return (n - LCS) + (m - LCS);
    }
};
