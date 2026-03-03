You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

// *************************************************************************Code**********************************************************************************
class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        for(int k=i;k<=j;k++){
            int temp_ans = solve(i,k-1,nums,dp) + solve(k+1,j,nums,dp) + nums[i-1] * nums[k] * nums[j+1];

            ans = max(ans,temp_ans);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(1,n-2,nums,dp);
    }
};

// *************************************************************************Intuition**********************************************************************************

Why Insert 1 at Beginning & End?
nums.insert(nums.begin(),1);
nums.push_back(1);

Treat edges safely

When last balloon is burst, neighbors always exist

Avoid out-of-bound checks

🔹 Meaning of solve(i, j)

Maximum coins obtainable by bursting balloons from i to j

Balloons outside this range are already burst

🔹 Base Case
if(i > j) return 0;

No balloons left → no coins

🔹 Core Idea (Very Important)

Instead of thinking:

“Which balloon to burst first?”

We think:

“Which balloon to burst LAST in this range?”

This avoids dependency problems.

🔹 Why Choose k as LAST?

If k is the last balloon burst in range [i, j]:

All balloons between i and j except k are already burst

So neighbors of k become:

nums[i-1]

nums[j+1]

So coins gained:

nums[i-1] * nums[k] * nums[j+1]

Then remaining problems:

Left → solve(i, k-1)

Right → solve(k+1, j)

🔹 Recurrence
dp[i][j] = max(
    solve(i,k-1) +
    solve(k+1,j) +
    nums[i-1] * nums[k] * nums[j+1]
)
🔹 Why NOT Burst First?

If you try bursting first:

Neighbors keep changing

Hard to define subproblem cleanly ❌

By choosing LAST:

Neighbors are fixed

Subproblems become independent ✅

🔹 Pattern Recognition

This is same structure as:

Matrix Chain Multiplication

Stick Cutting

All are:

“Choose one element inside range as last/first decision
Split into left + right
Add cost”
