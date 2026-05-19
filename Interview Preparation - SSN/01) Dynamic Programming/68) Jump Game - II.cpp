You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


// Greedy 
  class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;

        while(r < n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
        
    }
};

// Recursion
class Solution {
public:

    int solve(int i, vector<int>& nums){

        if(i >= nums.size()-1)
            return 0;

        int ans = INT_MAX;

        for(int jump=1;jump<=nums[i];jump++){

            int next = solve(i+jump, nums);

            if(next != INT_MAX)
                ans = min(ans , 1 + next);
        }

        return ans;
    }

    int jump(vector<int>& nums) {
        return solve(0, nums);
    }
};

// Bottom Up 
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, INT_MAX);

        dp[n-1] = 0;

        for(int i=n-2;i>=0;i--){

            for(int j=1;j<=nums[i] && i+j<n;j++){

                if(dp[i+j] != INT_MAX)
                    dp[i] = min(dp[i] , 1 + dp[i+j]);
            }
        }

        return dp[0];
    }
};
