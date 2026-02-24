// Recursion + Memoization 
class Solution {
  public:
    bool helper(vector<int>& arr, int sum, int idx, int target, vector<vector<int>>& dp){

        if(target == sum) return true;
        if(target > sum) return false;
        if(idx == arr.size()) return false;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool take = helper(arr,sum,idx+1,target+arr[idx],dp);
        bool leave = helper(arr,sum,idx+1,target,dp);
        
        return dp[idx][target] = take || leave;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return helper(arr,sum,0,0,dp);
    }
};

// Bottom Up 
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // dp[i][s] = can we make sum 's' using first 'i' elements
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // Base case: sum = 0 is always possible (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= sum; s++) {
                // Leave current element
                dp[i][s] = dp[i - 1][s];
                
                // Take current element if possible
                if (s >= arr[i - 1]) {
                    dp[i][s] = dp[i][s] || dp[i - 1][s - arr[i - 1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};
