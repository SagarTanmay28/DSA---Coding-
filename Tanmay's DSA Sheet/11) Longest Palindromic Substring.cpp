// Brute Force Approach 


class Solution {
private: 
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
}; 

// Optimised Approach 

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // Length 1 substrings
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Length 2 substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Length >= 3 substrings
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// Optimised Approach 

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







