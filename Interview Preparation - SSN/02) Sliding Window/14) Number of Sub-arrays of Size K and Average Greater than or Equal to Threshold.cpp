class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();

        int ans = 0;
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
                if(avg >= threshold) ans++;
            }
            j++;
        }

        return ans;
    }
};
