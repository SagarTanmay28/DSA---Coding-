Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.


class Solution {
public:
    int check(int mid, int k, vector<int>& nums){
        int n = nums.size();

        int subarrays = 1;
        int count = 0;

        for(int i=0;i<n;i++){
            count += nums[i];
            if(mid >= count) continue;
            else{
                subarrays++;
                count = nums[i];
            }
        }

        return subarrays <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;

        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);

        int ans = INT_MAX;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(mid,k,nums)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return ans;
    }
};
