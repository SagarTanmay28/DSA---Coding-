class Solution {
public:
    int solve(int i,vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        if(i >= strs.size()) return 0;
        if(m < 0 || n < 0) return -1e9;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int zeroes = 0;
        int ones = 0;
        for(char ch : strs[i]){
            if(ch == '0') zeroes++;
            else ones++;
        }

        int take = -1e9; // take = 0 we can use ?? check its very IMP
        if(zeroes <= m && ones <= n){
            take = 1 + solve(i+1,strs,m - zeroes, n - ones,dp);
        }

        int leave = solve(i+1,strs,m,n,dp);

        return dp[i][m][n] = max(take,leave);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int n1 = strs.size();

        vector<vector<vector<int>>> dp(n1,vector<vector<int>> (m + 1, vector<int>(n + 1,-1)));

        return solve(0,strs,m,n,dp);
        
    }
};
