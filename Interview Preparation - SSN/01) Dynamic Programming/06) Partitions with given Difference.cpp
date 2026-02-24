// Recursion + Memoization 
class Solution {
  public:
    int solve(int i, int target, vector<int>& arr, int diff, int sum, vector<vector<int>> &dp){
        if(i == arr.size()){
            if(target == sum) return 1;
            else return 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int take = 0;
        if(target + arr[i] <= sum){
            take = solve(i+1,target+arr[i],arr,diff,sum,dp);
        }
        
        int leave = solve(i+1,target,arr,diff,sum,dp);
        
        return dp[i][target] = take + leave;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        
        int total_sum = accumulate(arr.begin(),arr.end(),0);
        
        if((total_sum + diff) % 2 == 1) return 0;
        
        int sum = (total_sum + diff) / 2;
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return solve(0,0,arr,diff,sum,dp);
    }
};

// Bottom Up 
class Solution {
public:
    int countPartitions(vector<int>& v, int diff) {
        int sum = 0;
        int n = v.size();

        for (int i = 0; i < n; i++)
            sum += v[i];

        if (diff > sum)
            return 0;

        if ((diff + sum) % 2 != 0)
            return 0;

        int s2 = (diff + sum) / 2;

        int dp[n + 1][s2 + 1];

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= s2; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s2; j++) {
                if (v[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j]
                             + dp[i - 1][j - v[i - 1]];
            }
        }

        return dp[n][s2];
    }
};
