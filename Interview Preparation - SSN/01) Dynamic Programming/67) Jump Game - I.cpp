You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

//******************************************************************Greedy******************************************************************************************
  class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(i > maxi) return false;
            maxi = max(maxi,i + nums[i]);
        }
        return true;    
    }
};
//******************************************************************Top-Down******************************************************************************************
  class Solution {
public:

    bool solve(int i, vector<int>& nums, vector<int>& dp){

        if(i >= nums.size()-1)
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(int jump=1; jump<=nums[i]; jump++){
            if(solve(i+jump, nums, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return solve(0, nums, dp);
    }
};
//******************************************************************Bottom-Up***************************************************************************************
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        vector<bool> dp(n,false);

        dp[n-1] = true;

        for(int i=n-2;i>=0;i--){

            for(int j=1;j<=nums[i] && i+j<n;j++){

                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
