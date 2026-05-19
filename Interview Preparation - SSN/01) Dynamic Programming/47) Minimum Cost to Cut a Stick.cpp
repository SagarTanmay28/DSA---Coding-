
class Solution {
public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int k=i;k<=j;k++){
            int len = arr[j+1] - arr[i-1];
            int temp_ans = solve(i,k-1,arr,dp) + solve(k+1,j,arr,dp) + len;

            ans = min(ans,temp_ans);
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& arr) {
        arr.insert(arr.begin(),0);
        arr.push_back(n);

        sort(arr.begin(),arr.end());

        int m = arr.size();

        vector<vector<int>> dp(m,vector<int>(m,-1));

        return solve(1,m-2,arr,dp);
    }
};



Why we use solve(i, k-1) and solve(k+1, j)

k = the cut we are performing right now

Once we choose k, that cut is already done

So we must NOT include k again in subproblems

🔹 After cutting at k

Stick splits into:

Left side → cuts from i to k-1

Right side → cuts from k+1 to j

Remaining cuts are only those strictly left and right of k

🔹 Why NOT solve(i, k)?

That would include k again

It would try to cut at k twice ❌

Leads to double counting

🔹 Difference from MCM

In MCM:

k is a partition boundary → not removed

So we use (i, k) and (k+1, j)

In Stick Cutting:

k is an actual cut → removed

So we use (i, k-1) and (k+1, j)

🔥 Core Rule

If k is removed/used, exclude it → (i, k-1) & (k+1, j)

If k is just a partition boundary, include it on one side → (i, k) & (k+1, j)
