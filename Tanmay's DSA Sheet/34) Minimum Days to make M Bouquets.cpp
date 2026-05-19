class Solution {
public:
    bool check(int mid, int m, int k, vector<int>& nums){
        int n = nums.size();
        int bouquets = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            if(mid >= nums[i]) count++;
            else{
                bouquets += count / k;
                count = 0;
            }
        }

        bouquets += count / k;

        return bouquets >= m;

    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if((long long)m * k > n) return -1;

        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());

        int ans = INT_MAX;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(mid,m,k,nums)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return (ans != INT_MAX) ? ans : -1;
    }
};
