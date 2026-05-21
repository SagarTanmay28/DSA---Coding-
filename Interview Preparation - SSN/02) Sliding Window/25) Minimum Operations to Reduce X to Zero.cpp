You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // longest subarray with sum = totalSum - x 

        int n = nums.size();

        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int sum = 0;
        int maxi = INT_MIN;

        int target = totalSum - x;

        // edge case
        if(target < 0) return -1;

        if(target == 0) return n;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            sum += nums[j];

            while(sum > (totalSum - x)){
                sum -= nums[i];
                i++;
            }

            if(sum == (totalSum - x)){
                maxi = max(maxi,j-i+1);
            }
            j++;
        }

        return (maxi != INT_MIN) ? n - maxi : -1;
    }
};
