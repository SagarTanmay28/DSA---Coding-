class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start_idx = -1;
        int maxLen    = -1;
        
        // len = 1
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            maxLen = 1;
            start_idx = i;
        }
        // len = 2
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                maxLen = 2;
                start_idx = i;
            }
        }
        // len >= 3
        for(int len = 3; len <= n; len++){
            for(int i=0; i < n - len + 1; i++){
                int j = i + len - 1; 
                // j < n
                // i + len - 1 < n 
                // i < n - len + 1
                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    maxLen = len;
                    start_idx = i;
                }
            }
        }
        
        return s.substr(start_idx,maxLen);
        
    }
};
