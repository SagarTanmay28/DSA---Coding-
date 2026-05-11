Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int len = 0;
        int sum = 0;
        int minLen = INT_MAX;

        while(j<n){
            sum += nums[j];
            while(sum >= target){
                len = j-i+1;
                minLen = min(minLen,len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
        
    }
};
 
