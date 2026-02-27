class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int prevSum = 0;
        
        
        for(int i=0;i<k;i++){
            prevSum += arr[i];
        }
        
        int maxSum = prevSum;
        
        int i = 1;
        int j = k;
        
        while(j < n){
            int currSum = prevSum + arr[j] - arr[i-1];
            if(currSum > maxSum) maxSum = currSum;
            prevSum = currSum;
            i++;
            j++;
        }
        return maxSum;
        
    }
};
