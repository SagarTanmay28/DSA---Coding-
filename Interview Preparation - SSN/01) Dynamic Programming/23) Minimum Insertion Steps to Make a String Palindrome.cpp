class Solution {
public:
    int LCS(string& s, string& t, int i, int j, vector<vector<int>>& dp){

        if(i >= s.size() || j >= t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = 1 + LCS(s,t,i+1,j+1,dp);
        }
        else{
            int first = LCS(s,t,i+1,j,dp);
            int second = LCS(s,t,i,j+1,dp);
            return dp[i][j] = max(first,second);
        }

    }
    int minInsertions(string s) {

        string t = s;
        reverse(t.begin(),t.end());

        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int length = LCS(s,t,0,0,dp);

        return (n - length);
        
    }
};
