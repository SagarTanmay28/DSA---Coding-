class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j] < nums[i]) dp1[i] = max(dp1[i],dp1[j]);
            }

            dp1[i] += 1;
        }
        
        vector<int> dp2(n,0);

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i+1;j--){
                if(nums[j] < nums[i]) dp2[i] = max(dp2[i],dp2[j]);
            }

            dp2[i] += 1;
        }
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            if(dp1[i] > 1 && dp2[i] > 1)
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        
        if(maxi < 3) return 0;
        
        return n - maxi;
    }
};
