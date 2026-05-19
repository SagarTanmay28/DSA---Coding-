class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        vector<vector<int>> dp(n,vector<int>(n,0));

        // is Palindrome 
        for(int k=0;k<n;k++){
            int i = 0, j = k;

            while(j < n){
                // length = 1
                if(i == j){
                    dp[i][j] = 1;
                    count++;
                }
                // length = 2
                else if(j-i+1 == 2 && s[i] == s[j]){
                    dp[i][j] = 1;
                    count++;
                }
                // length > 2
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        count++;
                    }
                }

                i++;
                j++;
                
            }
        }

        return count;
    }
};
