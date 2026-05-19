Given an array of integers nums and an integer k, return the 
number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.




class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        if(k <= 1) return 0;

        int i = 0;
        int j = 0;
        long long product = 1;
        // Sliding Window 

        while(j < n){
            product *= nums[j];

            while(product >= k){
                product /= nums[i];
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }
};
