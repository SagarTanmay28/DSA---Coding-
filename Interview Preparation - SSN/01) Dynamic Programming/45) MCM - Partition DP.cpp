Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) 
for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.


class Solution {
  public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            int temp_ans = solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1] * arr[k] * arr[j];
            ans = min(ans,temp_ans);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(arr,1,n-1,dp);
    }
};
