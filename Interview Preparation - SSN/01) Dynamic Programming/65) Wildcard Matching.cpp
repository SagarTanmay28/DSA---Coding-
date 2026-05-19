Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0){
            for(int k = 0;k <= i;k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?') return dp[i][j] = solve(s,p,i-1,j-1,dp);
        if(p[i] == '*') return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(s,p,m-1,n-1,dp);
    }
};
