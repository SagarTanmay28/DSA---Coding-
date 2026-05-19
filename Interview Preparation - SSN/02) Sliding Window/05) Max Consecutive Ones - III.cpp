class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        int zeroes = 0;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            if(nums[j] == 0) zeroes++;

            while(zeroes > k){
                if(nums[i] == 0) zeroes--;
                i++;
            }

            max_len = max(max_len,j-i+1);
            j++;
        }

        return max_len;
    }
};
