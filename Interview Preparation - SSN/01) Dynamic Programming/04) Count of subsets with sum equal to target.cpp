// Recursion + Memoization 

class Solution {
  public:
    int solve(int i, int sum, vector<int>& arr, int target, vector<vector<int>> &dp){
       
        if(i == arr.size()){
            if(sum == target) return 1;
            else return 0;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take = 0;
        if(sum + arr[i] <= target){
            take = solve(i+1,sum+arr[i],arr,target,dp);
        }
        
        int leave = solve(i+1,sum,arr,target,dp);
        
        return dp[i][sum] = take + leave;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        return solve(0,0,arr,target,dp);
        
    }
};

// Bottom Up 
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        // 2D vector 
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        // initialize
        dp[0][0] = 1;
        
        // bottom-up
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                // take or leave
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
                // leave
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        // return last cell 
        return dp[n][target];
    }
};
