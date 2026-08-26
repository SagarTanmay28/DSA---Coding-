You are given an integer array nums and three integers k, op1, and op2.

You can perform the following operations on nums:

Operation 1: Choose an index i and divide nums[i] by 2, rounding up to the nearest whole number. You can perform this operation at most op1 times, and not more than once per index.
Operation 2: Choose an index i and subtract k from nums[i], but only if nums[i] is greater than or equal to k. You can perform this operation at most op2 times, and not more than once per index.
Note: Both operations can be applied to the same index, but at most once each.

Return the minimum possible sum of all elements in nums after performing any number of operations.

 

Example 1:

Input: nums = [2,8,3,19,3], k = 3, op1 = 1, op2 = 1

Output: 23

Explanation:

Apply Operation 2 to nums[1] = 8, making nums[1] = 5.
Apply Operation 1 to nums[3] = 19, making nums[3] = 10.
The resulting array becomes [2, 5, 3, 10, 3], which has the minimum possible sum of 23 after applying the operations.
Example 2:

Input: nums = [2,4,3], k = 3, op1 = 2, op2 = 1

Output: 3

Explanation:

Apply Operation 1 to nums[0] = 2, making nums[0] = 1.
Apply Operation 1 to nums[1] = 4, making nums[1] = 2.
Apply Operation 2 to nums[2] = 3, making nums[2] = 0.
The resulting array becomes [1, 2, 0], which has the minimum possible sum of 3 after applying the operations.

class Solution {
public:
    int n;

    int t[101][101][101];
    int solve(vector<int>& nums, int k, int i, int op1, int op2) {
        //Base Case
        if(i == n) {
            return 0;
        }
        if(t[i][op1][op2] != -1) {
            return t[i][op1][op2];
        }
        int result = INT_MAX; //minimum sum

        if(op1 > 0) {
            int newVal = (nums[i]+1)/2; //ceil(nums[i]/2.0);
            int applyOp1 = newVal + solve(nums, k, i+1, op1-1, op2);
            result = min(result, applyOp1);
        }

        if(op2 > 0 && nums[i] >= k) {
            int newVal = nums[i] - k;
            int applyOp2 = newVal + solve(nums, k, i+1, op1, op2-1);
            result = min(result, applyOp2);
        }

        //op1 -> op2 --- Case1
        //op2 -> op1 --- Case2
        if(op1 > 0 && op2 > 0) {
            int newVal = (nums[i]+1)/2; //apply op1

            if(newVal >= k) {
                newVal = newVal-k; //apply op2
                int applyOp1Op2 = newVal + solve(nums, k, i+1, op1-1, op2-1);
                result = min(result, applyOp1Op2);
            }

            if(nums[i] >= k) { //apply op2
                newVal = nums[i] - k;

                newVal = (newVal + 1)/2;  //apply op1

                int applyOp2Op1 = newVal + solve(nums, k, i+1, op1-1, op2-1);
                result = min(result, applyOp2Op1);
            }
        }

        //Applying no operation at nums[i]
        result = min(result, nums[i] + solve(nums, k, i+1, op1, op2));

        return t[i][op1][op2] = result;

    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, k, 0, op1, op2);
    }
};
