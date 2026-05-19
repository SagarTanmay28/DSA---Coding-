Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp){
        int n = s.size();
        int m = t.size();

        if(i == n) return m - j;
        if(j == m) return n - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = solve(i+1,j+1,s,t,dp);
        }
        else{
            return dp[i][j] = min({1 + solve(i+1,j+1,s,t,dp),1 + solve(i+1,j,s,t,dp),1 + solve(i,j+1,s,t,dp)});
        }
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(0,0,s,t,dp);
    }
};
