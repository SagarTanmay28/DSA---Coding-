The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1

// APPROACH 
  
To make frequency maximum, we try to make multiple smaller numbers equal to a bigger number.

Since increment operation is allowed, sorting helps.

Idea

After sorting:

Take a window [l ... r]
Try to make all elements equal to nums[r]
Required operations:
(nums[r]×window size)−sum of window

If operations required > k, shrink window.

// CODE 

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long sum = 0;

        int maxi = INT_MIN;

        int i = 0;
        int j = 0;

        // Sliding Window
        while(j < n){

            sum += nums[j];

            while((long long)nums[j] * (j - i + 1) - sum > k){
                sum -= nums[i];
                i++;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return (maxi == INT_MIN) ? 0 : maxi;
    }
};
