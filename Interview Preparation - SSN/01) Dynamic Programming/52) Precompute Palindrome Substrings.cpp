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
