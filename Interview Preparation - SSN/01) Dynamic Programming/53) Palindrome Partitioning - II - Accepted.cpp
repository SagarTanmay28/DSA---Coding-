// User function Template for C++

class Solution {
  public:
    
    // Precompute palindrome substrings
    void isPalindrome(vector<vector<bool>> &pal, string &s) {
        int n = s.size();

        // length = 1
        for(int i = 0; i < n; i++) 
            pal[i][i] = true;

        // length = 2
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i + 1])
                pal[i][i + 1] = true;
        }

        // length >= 3
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && pal[i + 1][j - 1])
                    pal[i][j] = true;
            }
        }
    }

    // Memoized recursion for minimum cuts
    int solve(int i, int j, string &s, vector<vector<int>> &dp, vector<vector<bool>> &pal) {

        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(pal[i][j]) 
            return dp[i][j] = 0;

        int ans = INT_MAX;

        for(int k = i; k < j; k++) {
            // Cut only if left part is palindrome (IMPORTANT)
            if(pal[i][k]) {
                int right = solve(k + 1, j, s, dp, pal);
                ans = min(ans, right + 1);
            }
        }

        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        if(n == 0) return 0;

        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<vector<int>> dp(n, vector<int>(n, -1));

        isPalindrome(pal, s);

        return solve(0, n - 1, s, dp, pal);
    }
};
