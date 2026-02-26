class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxi = INT_MIN;

        int sum = 0;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            sum += nums[j];

            while(j-i+1 > k){
                sum -= nums[i];
                i++;
            }

            if(j-i+1 == k){
                double avg = sum / (double)k;
                maxi = max(maxi,avg);
            }
            j++;
        }

        return maxi;
    }
};
