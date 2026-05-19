Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int n = nums.size();
        if(k > n) return 0;

        int count = 0;
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            mp[nums[j]]++;
            if(mp[nums[j]] == 1){
                k--; // new distinct element entered into map 
            }

            while(k < 0){ // shrink window 
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    k++;
                }
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
        
    }
};
