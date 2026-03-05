Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.

class Solution {
public:
    void isPalindrome(string &s, vector<vector<bool>>& pal){
        int n = s.size();

        // len = 1
        for(int i=0;i<n;i++) pal[i][i] = true;
        
        // len = 2
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]) pal[i][i+1] = true;
        }

        // len >= 3
        for(int len = 3; len <= n ; len++){
            for(int i=0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && pal[i+1][j-1] == true) pal[i][j] = true;
            }
        }
    }

    bool checkPartitioning(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n,vector<bool>(n,0));
        isPalindrome(s,pal);

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(pal[0][i] == true && pal[i+1][j] == true && pal[j+1][n-1] == true) return true;
            }
        }

        return false;
    }
};
