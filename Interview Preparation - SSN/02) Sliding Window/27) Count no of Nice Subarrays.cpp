Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int n = nums.size();

        int count = 0;
        int odds = 0;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            if(nums[j] % 2 == 1) odds++;

            while(odds > k){
                if(nums[i] % 2 == 1) odds--;
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
       int ans = atMost(nums,k) - atMost(nums,k-1);

       return ans;
    }
};

