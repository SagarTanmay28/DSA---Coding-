Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1class Solution {
public:
    int n;
    int t[501];
    int solve(vector<int>& arr, int idx, int k) {
        if(idx >= n) {
            return 0;
        }
        
        if(t[idx] != -1) {
            return t[idx];
        }
        
        int result = 0;
        int curr_max = -1;
        for(int i = idx; i < n && i-idx+1 <= k; i++) {
            curr_max = max(curr_max, arr[i]);
            
            result = max(result, curr_max*(i-idx+1) + solve(arr, i+1, k));
        }
        
        return t[idx] = result;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 0, k);
    }
};
