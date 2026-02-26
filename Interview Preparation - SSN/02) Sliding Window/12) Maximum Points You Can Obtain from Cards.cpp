There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


**Max score from picking k cards = Total sum − Minimum sum subarray of length (n − k)**

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        int mini = INT_MAX;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            sum += nums[j];

            while(j-i+1 > (n-k)){
                sum -= nums[i];
                i++;
            }

            if(j-i+1 == n-k) mini = min(mini,sum);
            j++;
        }

        int total_sum = accumulate(nums.begin(),nums.end(),0);

        return total_sum - mini;
    }
};
