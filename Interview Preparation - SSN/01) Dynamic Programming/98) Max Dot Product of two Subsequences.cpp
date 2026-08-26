/*
T.C = O(n * m);
S.C = O(n * m);
*/

class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
         int m = nums1.size();
         int n = nums2.size();

         if(i >= m || j >= n)  return -1e9;

         if(dp[i][j] != -1) return dp[i][j];

         long long maxi1 = nums1[i] * nums2[j]; // i & j
         long long maxi2 = (nums1[i] * nums2[j]) + solve(i+1,j+1,nums1,nums2,dp); // i & j + solve(i+1,j+1)
         long long maxi3 = solve(i+1,j,nums1,nums2,dp);
         long long maxi4 = solve(i,j+1,nums1,nums2,dp);

         return dp[i][j] = max({maxi1,maxi2,maxi3,maxi4});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        int ans = solve(0,0,nums1,nums2,dp);
        return ans;
        
    }
};
