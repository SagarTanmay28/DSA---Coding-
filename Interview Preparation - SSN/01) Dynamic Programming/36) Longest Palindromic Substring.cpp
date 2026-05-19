class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = INT_MIN;
        string ans = "";

        vector<vector<int>> dp(n,vector<int>(n,0));

        // is Palindrome 
        for(int k=0;k<n;k++){
            int i = 0, j = k;

            while(j < n){
                // length = 1
                if(i == j){
                    dp[i][j] = 1;
                    if(j-i+1 > maxi){
                        maxi = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                }
                // length = 2
                else if(j-i+1 == 2 && s[i] == s[j]){
                    dp[i][j] = 1;
                    if(j-i+1 > maxi){
                        maxi = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                }
                // length > 2
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        if(j-i+1 > maxi){
                            maxi = j-i+1;
                            ans = s.substr(i,j-i+1);
                        }
                    }
                }

                i++;
                j++;
                
            }
        }

        return ans;
    }
};
