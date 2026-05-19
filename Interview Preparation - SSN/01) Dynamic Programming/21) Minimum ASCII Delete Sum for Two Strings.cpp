class Solution {
public:
    int LCS(string& s1 , string& s2, int i, int j, vector<vector<int>>& dp){
        if(i >= s1.size() || j >= s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            char ch = s1[i];
            int x = (int)ch;
            return dp[i][j] = x + LCS(s1,s2,i+1,j+1,dp);
        }
        else{
            int first = LCS(s1,s2,i+1,j,dp);
            int second = LCS(s1,s2,i,j+1,dp);
            return dp[i][j] = max(first,second);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1,vector<int>(n2,-1));

        int sum_LCS = LCS(s1,s2,0,0,dp);
        int total_ASCII_sum = 0;

        for(int i=0;i<n1;i++) total_ASCII_sum += (int)s1[i];
        for(int i=0;i<n2;i++) total_ASCII_sum += (int)s2[i];

        int ans = total_ASCII_sum - (2 * sum_LCS);
        return ans;

        
    }
};
