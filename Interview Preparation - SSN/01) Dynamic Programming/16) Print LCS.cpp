#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Backtracking to print LCS
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs += s1[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Length of LCS: " << dp[n][m] << endl;
    cout << "LCS String: " << lcs;

    return 0;
}
