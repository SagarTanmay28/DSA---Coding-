// Recursion + Memoization -> Accepted 
class Solution {

  public:
    int minSumDiff(int i, vector<int>& arr, int total_sum, int curr_sum, vector<vector<int>>& dp){
        if(i >= arr.size()) return abs((total_sum - curr_sum) - curr_sum);
        
        if(dp[i][curr_sum] != -1) return dp[i][curr_sum];
        
        int take = minSumDiff(i+1, arr, total_sum, curr_sum + arr[i],dp);
        int leave = minSumDiff(i+1, arr, total_sum, curr_sum,dp);
        
        return dp[i][curr_sum] = min(take,leave);
    }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int total_sum = 0;
        for(int x : arr) total_sum += x;
        
        vector<vector<int>> dp(n+1,vector<int>(total_sum + 1,-1));
        
        return minSumDiff(0,arr,total_sum,0,dp);
    }
};

// Bottom Up -> TLE 

class Solution {
public:
    int minDifference(vector<int>& arr) {
        
        int n = arr.size();
        int total_sum = 0;
        for(int x : arr) total_sum += x;
        
        // dp[i][j] = can we make sum j using first i elements?
        vector<vector<bool>> dp(n+1, vector<bool>(total_sum+1, false));
        
        // Initialization
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;   // sum 0 always possible
        
        // Fill DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= total_sum; j++){
                
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        // Now find minimum difference
        int mini = INT_MAX;
        
        // Only need to check till total_sum/2
        for(int s1 = 0; s1 <= total_sum/2; s1++){
            if(dp[n][s1]){
                int diff = abs(total_sum - 2*s1);
                mini = min(mini, diff);
            }
        }
        
        return mini;
    }
};

// Bottom Up - Optimized 
class Solution {
public:
    int minDifference(vector<int>& arr) {
        
        int n = arr.size();
        int total_sum = 0;
        for(int x : arr) total_sum += x;
        
        int half = total_sum / 2;
        
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        
        for(int num : arr){
            for(int j = half; j >= num; j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        for(int s1 = half; s1 >= 0; s1--){
            if(dp[s1]){
                return total_sum - 2*s1;
            }
        }
        
        return 0;
    }
};
