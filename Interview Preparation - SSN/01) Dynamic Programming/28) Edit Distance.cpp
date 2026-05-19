// Forward 
class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
        int n = s1.size();
        int m = s2.size();

        if(i == s1.size()) return m - j;
        if(j == s2.size()) return n - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = solve(i+1,j+1,s1,s2,dp);
        else{
            int del = 1 + solve(i+1,j,s1,s2,dp);
            int insert = 1 + solve(i,j+1,s1,s2,dp);
            int replace = 1 + solve(i+1,j+1,s1,s2,dp);
            return dp[i][j] = min({insert,del,replace});
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(0,0,s1,s2,dp);
    }
};

// Backward 

class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]) return dp[i][j] = solve(a,b,i-1,j-1,dp);
        else{
            int add = 1 + solve(a,b,i,j-1,dp);
            int del = 1 + solve(a,b,i-1,j,dp);
            int replace = 1 + solve(a,b,i-1,j-1,dp);
            return dp[i][j] = min({add,del,replace});
        }
    }
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(a,b,m-1,n-1,dp);
    }
};
