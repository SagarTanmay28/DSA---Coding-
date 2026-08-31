There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.

class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {

        // Single character
        if (i == j)
            return 1;

        // Empty substring
        if (i > j)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Option 1:
        // Print s[i] separately
        int ans = 1 + solve(i + 1, j, s, dp);

        // Option 2:
        // If s[i] == s[k], print them in the same turn
        for (int k = i + 1; k <= j; k++) {

            if (s[i] == s[k]) {

                int cost = solve(i + 1, k - 1, s, dp)
                         + solve(k, j, s, dp);

                ans = min(ans, cost);
            }
        }

        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, s, dp);
    }
};
