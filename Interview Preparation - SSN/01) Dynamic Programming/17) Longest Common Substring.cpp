// Recursion + Memoization 
class Solution {
public:
    int ans = 0;

    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i >= s1.size() || j >= s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int curr = 0;
        if (s1[i] == s2[j]) {
            curr = 1 + solve(s1, s2, i + 1, j + 1, dp);
            ans = max(ans, curr);
        }

        // explore other starting points
        solve(s1, s2, i + 1, j, dp);
        solve(s1, s2, i, j + 1, dp);

        return dp[i][j] = curr;
    }

    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(s1, s2, 0, 0, dp);
        return ans;
    }
};

// Bottom Up 
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        int ans = 0;
        
        // Bottom Up
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // same 
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                // different
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
};
