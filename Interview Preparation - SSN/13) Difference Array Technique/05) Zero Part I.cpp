You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

 

Example 1:

Input: nums = [1,0,1], queries = [[0,2]]

Output: true

Explanation:

For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

Output: false

Explanation:

For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
The array will become [4, 2, 1, 0].
For i = 1:
Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
The array will become [3, 1, 0, 0], which is not a Zero Array.

//Approach - Straight Forward Difference Array Technique
//T.C : O(Q + n)
//S.C : O(Q + n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        //Step-1 Make diff array using query
        vector<int> diff(n, 0);
        for(auto &query : queries) {
            int start = query[0];
            int end   = query[1];
            int x     = 1;

            diff[start] += x;
            if(end+1 < n) {
                diff[end+1] -= x;
            }
        }

        //Step-2. Find cumulative effect on each index
        vector<int> result(n, 0);
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for(int i = 0; i < n; i++) {
            if(result[i] < nums[i]) { //nums[i] won't become 0 ever
                return false;
            }
        }

        return true;
    }
};
