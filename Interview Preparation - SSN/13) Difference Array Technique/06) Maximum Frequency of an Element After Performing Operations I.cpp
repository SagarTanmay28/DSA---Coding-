You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.

 

Example 1:

Input: nums = [1,4,5], k = 1, numOperations = 2

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].


//Approach - Using Difference Array Technique
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;

        vector<int> diff(maxVal+2, 0);
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;
        }


        int result = 1;

        for(int target = 0; target <= maxVal; target++) {
            diff[target] += (target > 0 ? diff[target-1] : 0);

            int targetFreq     = freq[target];
            int needConversion = diff[target] - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
};
