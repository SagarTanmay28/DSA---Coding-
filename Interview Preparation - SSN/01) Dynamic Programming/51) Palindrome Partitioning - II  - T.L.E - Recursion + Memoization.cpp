Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1

// T.L.E 

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
       
        while(i < j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        
        return 1;
    }
    
    int solve(string &s, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s,i,j)) return dp[i][j] = 0;
        
        int ans = INT_MAX;
        
        for(int k = i; k < j; k++){
            int left, right;
        
            if(dp[i][k] != -1)
                left = dp[i][k];
            else
                left = solve(s, i, k, dp);
        
            if(dp[k+1][j] != -1)
                right = dp[k+1][j];
            else
                right = solve(s, k+1, j, dp);
        
            ans = min(ans, left + right + 1);
        }
        
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(s,0,n-1,dp);
    }
};
